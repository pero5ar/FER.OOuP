package task4.generators;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.lang.Math;

public class NormalDistributionNumberGenerator implements INumberGenerator {
    private int mean;
    private double standardDeviation;
    private int size;
    private Random rnd;

    public NormalDistributionNumberGenerator(int mean, double stddev, int n) {
        this.mean = mean;
        this.standardDeviation = stddev;
        this.size = n;
        rnd = new Random();
    }

    @Override
    public List<Integer> generate() {
        List <Integer> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(Math.round( (float) (rnd.nextGaussian()*standardDeviation + mean)));
        }
        return list;
    }
}
