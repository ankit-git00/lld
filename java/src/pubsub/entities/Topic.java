package pubsub.entities;

import pubsub.subscriber.Subscriber;
import java.util.Set;
import java.util.concurrent.CopyOnWriteArraySet;
import java.util.concurrent.ExecutorService;


public class Topic {
    private final String name;
    private Set<Subscriber> subscribers;
    private final ExecutorService executorService;

    public Topic(String name, ExecutorService executorService){
        this.name = name;
        this.subscribers = new CopyOnWriteArraySet<>();
        this.executorService = executorService;
    }

    public String getName(){
        return this.name;
    }

    public void addSubscriber(Subscriber subscriber){
        this.subscribers.add(subscriber);
    }

    public void removeSubscriber(Subscriber subscriber){
        this.subscribers.remove(subscriber);
    }

    public void broadcast(Message message){
        for(Subscriber subscriber : subscribers){
            this.executorService.submit(() ->{
                subscriber.onMessage(message);
            });
        }
    }

    // public static void main(String[] args) {
    //   Topic topic = new Topic("SampleTopic", null);
    //   System.out.println(topic.getName());
    // }
}
