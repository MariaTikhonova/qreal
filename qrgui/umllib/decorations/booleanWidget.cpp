#include "booleanWidget.h"

BooleanWidget::BooleanWidget(Element *element, const QString &propertyName, QWidget *parent) :
	QCheckBox(parent),
	Control(propertyName),
	element(element)
{
	connect(
		this, SIGNAL(toggled(bool)),
		this, SLOT(setNewValue(bool))
	);
}

void BooleanWidget::setNewValue(const bool value) const {
	QString text;
	if (value) {
		text = "true";
	} else {
		text = "false";
	}
	element->setLogicalProperty(propertyName, text);
}
