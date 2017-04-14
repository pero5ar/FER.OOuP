package task4.generators;

import java.util.ArrayList;
import java.util.List;

public class NumberSequenceGenerator implements INumberGenerator {
    private int from;
    private int to;
    private int step;

    public NumberSequenceGenerator (int from, int to, int step){
        this.from = from;
        this.step = step;
        this.to = to;
    }

    @Override
    public List<Integer> generate() {
        List <Integer> list = new ArrayList<>();
        for (int i = from; i <= to; i+=step) {
            list.add(i);
        }
        return list;
    }
}
