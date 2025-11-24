import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static JLabel currentTimeLabel;
    private static DefaultListModel<String> alarmListModel;
    private static List<Alarm> alarms = new ArrayList<>();
    private static Alarm currentPlayingAlarm; // Reference to the currently ringing alarm

    public static void main(String[] args) {
        // Create Frame
        JFrame frame = new JFrame("Alarm Clock");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 500);
        frame.setLayout(new BorderLayout());

        // Current Time Display
        currentTimeLabel = new JLabel("", SwingConstants.CENTER);
        currentTimeLabel.setFont(new Font("Arial", Font.BOLD, 30));
        frame.add(currentTimeLabel, BorderLayout.NORTH);
        updateCurrentTime();

        // Alarm List Panel
        alarmListModel = new DefaultListModel<>();
        JList<String> alarmList = new JList<>(alarmListModel);
        alarmList.setFont(new Font("Arial", Font.PLAIN, 16));
        JScrollPane scrollPane = new JScrollPane(alarmList);
        frame.add(scrollPane, BorderLayout.CENTER);

        // Bottom Panel for Input and Buttons
        JPanel bottomPanel = new JPanel(new FlowLayout());
        JTextField hourField = new JTextField(2);
        hourField.setToolTipText("HH");
        JTextField minuteField = new JTextField(2);
        minuteField.setToolTipText("MM");
        JTextField secondField = new JTextField(2);
        secondField.setToolTipText("SS");
        JButton addAlarmButton = new JButton("Add Alarm");
        JButton stopAllButton = new JButton("Stop All Alarms");
        JButton stopMusicButton = new JButton("Stop Music"); // New button to stop music

        bottomPanel.add(new JLabel("HH:"));
        bottomPanel.add(hourField);
        bottomPanel.add(new JLabel("MM:"));
        bottomPanel.add(minuteField);
        bottomPanel.add(new JLabel("SS:"));
        bottomPanel.add(secondField);
        bottomPanel.add(addAlarmButton);
        bottomPanel.add(stopAllButton);
        bottomPanel.add(stopMusicButton); // Add stop music button
        frame.add(bottomPanel, BorderLayout.SOUTH);

        // Add Alarm Button Action
        addAlarmButton.addActionListener(e -> {
            try {
                int hour = Integer.parseInt(hourField.getText());
                int minute = Integer.parseInt(minuteField.getText());
                int second = Integer.parseInt(secondField.getText());
                LocalTime alarmTime = LocalTime.of(hour, minute, second);

                Alarm alarm = new Alarm(alarmTime);
                alarms.add(alarm);
                currentPlayingAlarm = alarm; // Update current alarm
                alarm.start();

                alarmListModel.addElement("Alarm set for: " + alarmTime);

                // Clear Input Fields
                hourField.setText("");
                minuteField.setText("");
                secondField.setText("");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(frame,
                    "Invalid input. Please enter valid HH:MM:SS.",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            }
        });

        // Stop All Alarms Button Action
        stopAllButton.addActionListener(e -> {
            for (Alarm alarm : alarms) {
                alarm.stop();
            }
            alarms.clear();
            alarmListModel.clear();
        });

        // Stop Music Button Action
        stopMusicButton.addActionListener(e -> {
            if (currentPlayingAlarm != null) {
                currentPlayingAlarm.stopSound();
            }
        });

        // Show Frame
        frame.setVisible(true);
    }

    private static void updateCurrentTime() {
        Timer timer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                LocalTime now = LocalTime.now();
                currentTimeLabel.setText(now.format(java.time.format.DateTimeFormatter.ofPattern("HH:mm:ss")));
            }
        });
        timer.start();
    }
}
