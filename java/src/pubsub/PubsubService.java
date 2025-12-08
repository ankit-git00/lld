package pubsub;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import pubsub.subscriber.Subscriber;
import pubsub.entities.Message;
import pubsub.entities.Topic;

public class PubsubService {
    private  final ConcurrentHashMap<String, Topic> topicRegistry;
    private static final PubsubService INSTANCE = new PubsubService();
    private final ExecutorService deliveryExecutor;

     public static void main(String[] args) {
     
        System.out.println("PubSub Service is running.");
    }

    public PubsubService(){
        this.topicRegistry = new ConcurrentHashMap<>();
        this.deliveryExecutor = Executors.newCachedThreadPool();
    }

    public static PubsubService getInstance(){
        return INSTANCE;
    }

    public void createTopic(String topicName){
        this.topicRegistry.putIfAbsent(topicName, new Topic(topicName, deliveryExecutor)); // all topic use the same thread pool, 
        // so a hot topic can consume all threads, also we can't apply topic level threading limits( like the max number of threads)
    }

    public void subscribe(String topicName, Subscriber subscriber){
        Topic topic = this.topicRegistry.get(topicName);
        if(topic != null){
            topic.addSubscriber(subscriber);
        }
    }

    public void unSubscribe(String topicName, Subscriber subscriber){
        Topic topic = this.topicRegistry.get(topicName);
        if(topic != null){
            topic.removeSubscriber(subscriber);
        }
    }
    
    public void publish(String topicName, Message message){
        Topic topic = this.topicRegistry.get(topicName);
        if(topic != null){
            topic.broadcast(message);
        }

    }

    public void shutDown(){

        this.deliveryExecutor.shutdown();
        try{
            if(!this.deliveryExecutor.awaitTermination(60, java.util.concurrent.TimeUnit.SECONDS)){
                this.deliveryExecutor.shutdownNow();
            }
        }
        catch(InterruptedException e){
            this.deliveryExecutor.shutdownNow();
            Thread.currentThread().interrupt(); // because we caught the interrupt, we need to propagte it to the higher level
        }

        System.out.println("PubSub Service shutdown complete.");
    }

   
}
