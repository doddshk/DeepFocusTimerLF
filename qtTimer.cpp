#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

class Pomodoro : public QObject {
  Q_OBJECT

public:
  Pomodoro() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Pomodoro::onTimerTimeout);

    startButton = new QPushButton("Start");
    connect(startButton, &QPushButton::clicked, this,
            &Pomodoro::onStartButtonClicked);

    layout = new QVBoxLayout;
    layout->addWidget(startButton);

    widget = new QWidget;
    widget->setLayout(layout);
    widget->show();
  }

public slots:
  void onStartButtonClicked() {
    qDebug() << "Start button clicked!";
    startPomodoro(25, 5); // Start a Pomodoro session with default times
  }

  void onTimerTimeout() { qDebug() << "Pomodoro session finished!"; }

private:
  QTimer *timer;
  QPushButton *startButton;
  QVBoxLayout *layout;
  QWidget *widget;

  void startPomodoro(int workTime, int breakTime) {
    qDebug() << "Pomodoro session started. Work for" << workTime << "minutes.";
    timer->start(workTime * 60 * 1000); // Convert minutes to milliseconds
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Pomodoro pomodoro;
  return app.exec();
}

#include "main.moc"
