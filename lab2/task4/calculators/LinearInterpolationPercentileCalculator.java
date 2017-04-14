package task4.calculators;

import java.util.Collections;
import java.util.List;

public class LinearInterpolationPercentileCalculator implements IPercentileCalculator {

    public int calculatePercentile(int p, List<Integer> numbers) {
        /* RULES:
                p(v[i]) = 100*(i-0.5)/N;
                v(p) = v[i] + N * (p-p(v[i]))*(v[i+1]-v[i])/100;
        */
        /* NOTE:
                p(v[i]) <=> p_v_i,
                p(v[i+1]) <=> p_v_ii
         */
        Collections.sort(numbers);
        int N = numbers.size();
        double p_v_1 = 100*0.5 / (double) N;  // p(v[1])
        double p_v_N = 100*(N - 1) / (double) N;  // p(v[N])
        if (p <= p_v_1) return numbers.get(0);
        if (p >= p_v_N) return numbers.get(N-1);

        double p_v_i = p_v_1;
        double p_v_ii;
        for (int i = 2; i <= N; i++) { // skip the first one
            p_v_ii = 100*(i-0.5) / (double) N;
            if (p >= p_v_i && p <= p_v_ii) {
                double v_i = numbers.get(i-2);  // numbers start from 0
                double v_ii = numbers.get(i-1);
                return (int) ( v_i + N*(p - p_v_i)*(v_i - v_ii) / 100.0 );
            }
            p_v_i = p_v_ii;
        }
        return numbers.get(N-1);
    }

}

