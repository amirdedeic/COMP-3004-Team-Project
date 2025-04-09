#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QGroupBox>

// Function to update time label
void updateTimeLabel(QLabel *label) {
    QDateTime now = QDateTime::currentDateTime();
    QString timeStr = now.toString("yyyy-MM-dd hh:mm:ss");
    label->setText("Current time: " + timeStr);
    qDebug() << "Updated time:" << timeStr;
}

// Function to setup database
bool setupDatabase(QLabel *statusLabel) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    
    if (!db.open()) {
        statusLabel->setText("DB Error: " + db.lastError().text());
        qDebug() << "Database: connection failed:" << db.lastError().text();
        return false;
    }
    
    // Create a simple table
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS logs (id INTEGER PRIMARY KEY, timestamp TEXT, message TEXT)");
    
    statusLabel->setText("Database connected successfully");
    qDebug() << "Database: connection ok";
    return true;
}

// Function to log event to database
void logEvent(const QString &message, QLabel *statusLabel) {
    QDateTime now = QDateTime::currentDateTime();
    QString timestamp = now.toString("yyyy-MM-dd hh:mm:ss");
    
    QSqlQuery query;
    query.prepare("INSERT INTO logs (timestamp, message) VALUES (?, ?)");
    query.addBindValue(timestamp);
    query.addBindValue(message);
    
    if (query.exec()) {
        statusLabel->setText("Event logged: " + message);
        qDebug() << "Event logged:" << message;
    } else {
        statusLabel->setText("Failed to log event: " + query.lastError().text());
        qDebug() << "Failed to log event:" << query.lastError().text();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Create main window
    QMainWindow window;
    window.setWindowTitle("Full Test Application");
    window.resize(500, 400);
    
    // Create central widget and main layout
    QWidget *centralWidget = new QWidget(&window);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Create time display section
    QGroupBox *timeBox = new QGroupBox("Time Information", centralWidget);
    QVBoxLayout *timeLayout = new QVBoxLayout(timeBox);
    QLabel *timeLabel = new QLabel("Time will appear here", timeBox);
    QPushButton *updateTimeButton = new QPushButton("Update Time", timeBox);
    timeLayout->addWidget(timeLabel);
    timeLayout->addWidget(updateTimeButton);
    
    // Create database section
    QGroupBox *dbBox = new QGroupBox("Database Operations", centralWidget);
    QVBoxLayout *dbLayout = new QVBoxLayout(dbBox);
    QLabel *dbStatusLabel = new QLabel("Database status", dbBox);
    QPushButton *connectButton = new QPushButton("Connect to Database", dbBox);
    QPushButton *logButton = new QPushButton("Log Event", dbBox);
    dbLayout->addWidget(dbStatusLabel);
    dbLayout->addWidget(connectButton);
    dbLayout->addWidget(logButton);
    
    // Add sections to main layout
    mainLayout->addWidget(timeBox);
    mainLayout->addWidget(dbBox);
    
    // Add status bar
    QLabel *statusLabel = new QLabel("Ready");
    mainLayout->addWidget(statusLabel);
    
    // Connect signals and slots
    QObject::connect(updateTimeButton, &QPushButton::clicked, [timeLabel]() {
        updateTimeLabel(timeLabel);
    });
    
    QObject::connect(connectButton, &QPushButton::clicked, [dbStatusLabel]() {
        setupDatabase(dbStatusLabel);
    });
    
    QObject::connect(logButton, &QPushButton::clicked, [dbStatusLabel]() {
        logEvent("User clicked the Log Event button", dbStatusLabel);
    });
    
    // Set central widget
    window.setCentralWidget(centralWidget);
    
    // Show the window
    window.show();
    
    // Initial time update
    updateTimeLabel(timeLabel);
    
    return a.exec();
} 