package task5;

import task5.actions.*;
import task5.source.FileSource;
import task5.source.KeyboardSource;
import java.io.File;
import java.nio.file.Paths;

public class Main {

    public static void main(String[] args) {
        System.out.println("Set file source: ");
        File file = Paths.get("res", "numbers.txt").toFile();
        NumberSequence numberSequence = new NumberSequence(new FileSource(file));

        BaseAction average = new Average(numberSequence);
        BaseAction median = new Median(numberSequence);
        BaseAction sum = new Sum(numberSequence);
        BaseAction log = new Log(numberSequence);
        numberSequence.kreni();

        median.setSource(null);
        System.out.println("Set keyboard source: ");
        numberSequence.setSource(new KeyboardSource());
        numberSequence.kreni();
    }
}
