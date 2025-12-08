package pubsub.entities;

import java.time.Instant;

public class Message {

    // public static void main(String[] args) {
    //     Message message = new Message("Hello, PubSub!");
    //     System.out.println(message.toString());
    // }

    private final String content;
    public final Instant timeStamp;

    public Message(String content){
        this.content = content;
        this.timeStamp = Instant.now();
    }

    public String gretContent(){
        return this.content;
    }

    @Override
    public String toString(){
        return "Message{" + "content = '" + content + '\'' + '}';
    }

   
};

