#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QDateTime>
#include <QDebug>

void updateTimeLabel(QLabel *label) {
    // Use QDateTime - this is where crashes often happen
    QDateTime now = QDateTime::currentDateTime();
    QString timeStr = now.toString("yyyy-MM-dd hh:mm:ss");
    label->setText("Current time: " + timeStr);
    qDebug() << "Updated time:" << timeStr;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Create a simple window with no custom classes
    QMainWindow window;
    window.setWindowTitle("DateTime Test");
    window.resize(400, 300);
    
    // Create central widget and layout
    QWidget *centralWidget = new QWidget(&window);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    // Add some basic widgets
    QLabel *timeLabel = new QLabel("Time will appear here", centralWidget);
    QPushButton *updateButton = new QPushButton("Update Time", centralWidget);
    
    // Add widgets to layout
    layout->addWidget(timeLabel);
    layout->addWidget(updateButton);
    
    // Connect button click to update time
    QObject::connect(updateButton, &QPushButton::clicked, [timeLabel]() {
        updateTimeLabel(timeLabel);
    });
    
    // Set central widget
    window.setCentralWidget(centralWidget);
    
    // Show the window
    window.show();
    
    // Initial time update
    updateTimeLabel(timeLabel);
    
    return a.exec();
} 