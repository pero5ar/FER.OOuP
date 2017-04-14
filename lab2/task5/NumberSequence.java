package task5;


import task5.actions.BaseAction;
import task5.source.INumbersSource;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * SlijedBrojeva
 */
public class NumberSequence {
    private INumbersSource source;
    private Collection<BaseAction> observers;
    private List<Integer> numberSequence;

    public NumberSequence(INumbersSource source) {
        this.source = source;
        observers = new ArrayList<>();
        numberSequence = new ArrayList<>();
    }

    public INumbersSource getSource() {
        return source;
    }

    public void setSource(INumbersSource source) {
        this.source = source;
    }

    public List<Integer> getNumberSequence() {
        return new ArrayList<>(numberSequence);
    }

    public void attach(BaseAction action) {
        observers.add(action);
    }

    public void dettach(BaseAction action) {
        observers.remove(action);
    }

    private void notifyObservers() {
        for (BaseAction action : observers) {
            action.update();
        }
    }

    public void kreni() {
        int num;
        while ((num = source.next()) >= 0){
            numberSequence.add(num);
            notifyObservers();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
