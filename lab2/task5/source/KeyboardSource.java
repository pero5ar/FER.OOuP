package task5.source;

import java.util.Scanner;

/**
 * TipkovnickiIzvor
 */
public class KeyboardSource implements INumbersSource {
    private Scanner reader;

    public KeyboardSource() {
        reader = new Scanner(System.in);
    }

    @Override
    public int next() {
        return reader.nextInt();
    }
}
