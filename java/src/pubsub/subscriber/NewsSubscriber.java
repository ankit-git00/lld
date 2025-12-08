package pubsub.subscriber;

import pubsub.entities.Message;

public class NewsSubscriber implements Subscriber {
    private final String id;

    public  NewsSubscriber(String id) {
        this.id = id;
    }   

    public String getId() {
        return id;
    }   

    public void onMessage(Message message) {
        System.out.println("NewsSubscriber " + id + " received message: " + message.toString());
    }
}
