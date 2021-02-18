#pragma once
#include <QPushButton>

class QLabel;
class MyButton : public QPushButton
{
	Q_OBJECT
public:
	MyButton(QWidget* parent = nullptr);

protected:
	bool event(QEvent* e) override;

private:
	QLabel* m_pTextLabel = nullptr;
	QLabel* m_pImgLabel = nullptr;

};
