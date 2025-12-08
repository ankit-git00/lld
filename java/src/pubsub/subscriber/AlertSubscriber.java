package pubsub.subscriber;

import pubsub.entities.Message;

public class AlertSubscriber implements Subscriber {
    private final String id;

    public AlertSubscriber(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }   

    public void onMessage(Message message) {
        System.out.println("AlertSubscriber " + id + " received message: " + message.toString());
    }
}
