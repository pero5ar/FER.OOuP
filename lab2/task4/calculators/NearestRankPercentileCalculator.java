package task4.calculators;

import java.util.Collections;
import java.util.List;

public class NearestRankPercentileCalculator implements IPercentileCalculator {

    public int calculatePercentile(int p, List<Integer> numbers) {
        Collections.sort(numbers);
        int N = numbers.size();
        int n_p = (int) Math.round(p * N/100.0 + 0.5);
        if (n_p > N) return numbers.get(N-1); // happens at p >= 95
        return numbers.get(n_p-1);
    }
}
