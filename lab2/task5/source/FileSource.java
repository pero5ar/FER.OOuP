package task5.source;

import java.io.*;

/**
 * DatotecniIzvor
 */
public class FileSource implements INumbersSource {
    private final int TERMINATOR = -1;
    private BufferedReader reader;

    public FileSource(File file) {
        try {
            reader = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public int next() {
        try {
            String line = reader.readLine();
            if (line == null) {
                return TERMINATOR;
            }
            return Integer.parseInt(line);
        } catch (IOException e) {
            return TERMINATOR;
        }
    }
}
