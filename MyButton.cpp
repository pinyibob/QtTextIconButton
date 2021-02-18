#include "MyButton.h"
#include <QLabel>
#include <QHBoxLayout>
#include <qvariant.h>
#include <QEvent>
#include <QStyle>
#include <qapplication.h>
#include <QWidget>

MyButton::MyButton(QWidget* parent)
	:QPushButton(parent)
{
	setObjectName("aBtn");
	m_pTextLabel = new QLabel(this);
	m_pImgLabel = new QLabel(this);

	QHBoxLayout* filay = new QHBoxLayout(this);
	filay->setContentsMargins(8, 4, 8, 4);
	filay->setSpacing(8);
	filay->addWidget(m_pImgLabel);
	filay->addWidget(m_pTextLabel);

	m_pImgLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_pTextLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

	m_pImgLabel->setObjectName("ImgLabel");
	m_pImgLabel->setText("img");
	m_pTextLabel->setObjectName("TextLabel");
	m_pTextLabel->setText("text");
}

bool MyButton::event(QEvent* e)
{
	auto repolish = [](QWidget* p)->void {
		p->style()->unpolish(p);
		p->style()->polish(p);
	};

	switch (e->type())
	{
	case QEvent::MouseButtonPress:
		m_pImgLabel->setProperty("state", "press");
		repolish(m_pImgLabel);
		m_pTextLabel->setProperty("state", "press");
		repolish(m_pTextLabel);
		break;
		
	case QEvent::MouseButtonRelease:
		m_pImgLabel->setProperty("state", "normal");
		repolish(m_pImgLabel);
		m_pTextLabel->setProperty("state", "normal");
		repolish(m_pTextLabel);
		break;

	case QEvent::Enter:
		m_pImgLabel->setProperty("state","enter");
		repolish(m_pImgLabel);
		m_pTextLabel->setProperty("state", "enter");
		repolish(m_pTextLabel);
		break;

	case QEvent::Leave:
		m_pImgLabel->setProperty("state","normal");
		repolish(m_pImgLabel);
		m_pTextLabel->setProperty("state", "normal");
		repolish(m_pTextLabel);
		break;
	}
	
	return __super::event(e);
}
