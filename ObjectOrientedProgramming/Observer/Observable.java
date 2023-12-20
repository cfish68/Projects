//package WS1.Observables;

//import WS1.Observers.Observer;

import java.util.LinkedList;

public class Observable{
    LinkedList<Observer> Observers;
    public Observable()
    {
        Observers = new LinkedList<>();
    }
    public void addObserver(Observer observer)
    {
        Observers.add(observer);
        System.out.println(observer.getClass().getSimpleName() + " observes " + this.toString());
    }
    void notifyObservers(int data)
    {
        for(Observer observer : Observers)
        {
            observer.update(data);
        }
    }
}
