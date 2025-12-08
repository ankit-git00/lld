package pubsub.subscriber;

import pubsub.entities.Message;

public interface Subscriber {

    String getId();
    void onMessage(Message message);

}


// created the subscriber interface and message and topic class, need to implement the interface
// impelement pubSubService and implete subscriber