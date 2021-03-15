#ifndef PROGRESSEVENT_H
#define PROGRESSEVENT_H

#include <QEvent>

class ProgressEvent : public QEvent
{
public:
    enum {EventId = QEvent::User +1};
    ProgressEvent( int progress = 0);



    int progress() const;

private:
    int m_progress;
};

#endif // PROGRESSEVENT_H
