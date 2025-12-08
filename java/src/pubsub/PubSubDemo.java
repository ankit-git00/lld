package pubsub;


import pubsub.entities.Message;
import pubsub.entities.Topic;
import pubsub.subscriber.*;

public class PubSubDemo {

    public static void main(String[] args) {
    PubsubService pubsubService = PubsubService.getInstance();

    Subscriber subscriber1 = new NewsSubscriber("s1");
    Subscriber subscriber2 = new AlertSubscriber("s2");
    Subscriber subscriber3 = new NewsSubscriber("s3");

    final String SPORTS_TOPIC = "SPORTS";
    final String TECH_TOPIC = "TECH";
    final String WEATHER_TOPIC = "WEATHER";

    pubsubService.createTopic(SPORTS_TOPIC);
    pubsubService.createTopic(TECH_TOPIC);
    pubsubService.createTopic(WEATHER_TOPIC);

    pubsubService.subscribe(WEATHER_TOPIC, subscriber1);
    pubsubService.subscribe(TECH_TOPIC, subscriber2);
    pubsubService.subscribe(SPORTS_TOPIC, subscriber1);
    pubsubService.subscribe(SPORTS_TOPIC, subscriber2);
    pubsubService.subscribe(SPORTS_TOPIC, subscriber3);
    pubsubService.subscribe(TECH_TOPIC, subscriber3);
    pubsubService.subscribe(WEATHER_TOPIC, subscriber3);

    Message techMessage = new Message("New Java Version Released");
    Message weatherMessage = new Message("Heavy Rain Expected Tomorrow");
    Message sportsMessage = new Message("Local Team Wins Championship");

    pubsubService.publish(WEATHER_TOPIC, weatherMessage);
    pubsubService.publish(SPORTS_TOPIC, sportsMessage);
    pubsubService.publish(TECH_TOPIC, techMessage);

    // pubsubService.unSubscribe(WEATHER_TOPIC, subscriber3);
    // pubsubService.unSubscribe(WEATHER_TOPIC, subscriber1);
    pubsubService.publish(WEATHER_TOPIC, weatherMessage);

    for (int i = 0; i < 5; i++) {
        pubsubService.publish(WEATHER_TOPIC, new Message("Weather Update " + i));
    }

    pubsubService.shutDown();


}
}


// complete the demo and write what you learn along with the just (chunk the solution) , expalin observer pattern in this context agiain

