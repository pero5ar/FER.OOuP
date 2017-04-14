package task5.actions;

import task5.NumberSequence;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collection;

public class Log extends BaseAction {
    private Path file;

    public Log(NumberSequence subject) {
        super(subject);
        file = Paths.get("res", "log.txt");
        createFile();
    }

    public Log(NumberSequence subject, Path filePath) {
        super(subject);
        file = filePath;
        createFile();
    }

    private void createFile() {
        File f = file.toFile();
        if(!f.exists() || !f.isFile()) {
            try {
                f.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void update() {
        Collection<String> log = new ArrayList<>();
        log.add("---");
        log.add(LocalDateTime.now().toString());
        log.add(this.source.getNumberSequence().toString());
        log.add("---");
        try {
            Files.write(file, log, Charset.forName("UTF-8"), StandardOpenOption.APPEND);
        } catch (IOException e) {
            this.source.dettach(this);
        }
    }
}
