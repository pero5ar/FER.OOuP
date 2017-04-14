package task4.generators;

import java.util.ArrayList;
import java.util.List;

public class FibonacciNumberGenerator implements INumberGenerator {
    private int size;

    public FibonacciNumberGenerator(int n) {
        this.size = n;
    }

    @Override
    public List<Integer> generate() {
        List <Integer> list = new ArrayList<>();
        for (int i = 0, prevFib = 0, fib = 1; i < size; i++) {
            list.add(fib);

            int fibTemp = prevFib;
            prevFib = fib;
            fib += fibTemp;
        }
        return list;
    }
}
