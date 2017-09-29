#include "teamleadersdialog.h"
#include <QStringListModel>
#include <QListView>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>

TeamLeadersDialog::TeamLeadersDialog(const QStringList &leaders,
                                     QWidget *parent)
    : QDialog(parent)
{
    model = new QStringListModel(this);
    model->setStringList(leaders);

    listView = new QListView;
    listView->setModel(model);
    listView->setEditTriggers(QAbstractItemView::AnyKeyPressed
                              | QAbstractItemView::DoubleClicked);

    buttonBox = new QDialogButtonBox();
    QPushButton *insertButton = buttonBox->addButton(tr("&Insert"),
            QDialogButtonBox::ActionRole);
    QPushButton *deleteButton = buttonBox->addButton(tr("&Delete"),
            QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(insertButton, &QPushButton::clicked, this, &TeamLeadersDialog::insert);
    connect(deleteButton, &QPushButton::clicked, this, &TeamLeadersDialog::del);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &TeamLeadersDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &TeamLeadersDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(listView);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Team Leaders"));
}

QStringList TeamLeadersDialog::leaders() const
{
    return model->stringList();
}

void TeamLeadersDialog::insert()
{
    int row = listView->currentIndex().row();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);
    listView->setCurrentIndex(index);
    listView->edit(index);
}

void TeamLeadersDialog::del()
{
    model->removeRows(listView->currentIndex().row(), 1);
}
