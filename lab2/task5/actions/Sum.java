package task5.actions;

import task5.NumberSequence;
import java.util.Collection;

public class Sum extends BaseAction {

    public Sum(NumberSequence source) {
        super(source);
    }

    @Override
    public void update() {
        Collection<Integer> numbers = this.source.getNumberSequence();
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        System.out.println("Sum: " + sum);
    }
}
