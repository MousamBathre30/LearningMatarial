import javax.swing.*;
import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;
import java.time.LocalTime;
import java.util.Timer;
import java.util.TimerTask;

public class Alarm {
    private LocalTime alarmTime;
    private Timer timer;
    private Clip clip; // Reference to the clip

    public Alarm(LocalTime alarmTime) {
        this.alarmTime = alarmTime;
        this.timer = new Timer();
    }

    public void start() {
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                LocalTime now = LocalTime.now();
                if (now.getHour() == alarmTime.getHour() &&
                    now.getMinute() == alarmTime.getMinute() &&
                    now.getSecond() == alarmTime.getSecond()) {

                    SwingUtilities.invokeLater(() -> {
                        JOptionPane.showMessageDialog(null,
                            "Alarm ringing for: " + alarmTime,
                            "Alarm",
                            JOptionPane.INFORMATION_MESSAGE);
                    });
                    playSound("music.wav"); // Play sound
                    stop();
                }
            }
        }, 0, 1000); // Check every second
    }

    public void stop() {
        timer.cancel();
        stopSound(); // Stop the sound if playing
    }

    public void stopSound() {
        if (clip != null && clip.isRunning()) {
            clip.stop();
            clip.close();
        }
    }

    public LocalTime getAlarmTime() {
        return alarmTime;
    }

    private void playSound(String soundFileName) {
        try {
            File soundFile = new File(soundFileName);
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(soundFile);
            clip = AudioSystem.getClip();
            clip.open(audioStream);
            clip.start();
        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException e) {
            JOptionPane.showMessageDialog(null,
                "Error playing sound: " + e.getMessage(),
                "Error",
                JOptionPane.ERROR_MESSAGE);
        }
    }
}
