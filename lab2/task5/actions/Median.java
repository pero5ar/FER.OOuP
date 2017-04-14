package task5.actions;

import task5.NumberSequence;
import java.util.Collections;
import java.util.List;

public class Median extends BaseAction {

    public Median(NumberSequence source) {
        super(source);
    }

    @Override
    public void update() {
        List<Integer> numbers = this.source.getNumberSequence();
        Collections.sort(numbers);
        int N = numbers.size();
        double median = ( N % 2 == 1) ? numbers.get(N/2) : (numbers.get(N/2) + numbers.get(N/2 - 1)) / 2.0;
        System.out.println("Median: " + median);
    }
}
