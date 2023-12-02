/*****************************************************************************
 * FILE NAME    : ModuleToolBar.cpp
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleToolBar.h"

/*****************************************************************************!
 * Function : ModuleToolBar
 *****************************************************************************/
ModuleToolBar::ModuleToolBar
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);

  setFrameShape(QFrame::Panel);
  setFrameShadow(QFrame::Sunken);
  setLineWidth(2);

  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleToolBar
 *****************************************************************************/
ModuleToolBar::~ModuleToolBar
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleToolBar::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  ActionDisplayModulesButtonPushed = new QAction("DisplayModulesButtonPushed", this);
  connect(ActionDisplayModulesButtonPushed, SIGNAL(triggered()), this, SLOT(SlotDisplayModulesButtonPushed()));
  ActionDisplaySourceFilesButtonPushed = new QAction("DisplaySourceFilesButtonPushed", this);
  connect(ActionDisplaySourceFilesButtonPushed, SIGNAL(triggered()), this, SLOT(SlotDisplaySourceFilesButtonPushed()));
  ActionDisplayTargetsButtonPushed = new QAction("DisplayTargetsButtonPushed", this);
  connect(ActionDisplayTargetsButtonPushed, SIGNAL(triggered()), this, SLOT(SlotDisplayTargetsButtonPushed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleToolBar::CreateSubWindows()
{
  //! Create the DisplayModulesButton button  
  DisplayModulesButton = new QPushButton();
  DisplayModulesButton->setParent(this);
  DisplayModulesButton->setText("M");
  DisplayModulesButton->move(0, 1);
  DisplayModulesButton->resize(24,24);
  connect(DisplayModulesButton, SIGNAL(pressed()), this, SLOT(SlotDisplayModulesButtonPushed()));

  //! Create the DisplaySourceFilesButton button
  DisplaySourceFilesButton = new QPushButton();
  DisplaySourceFilesButton->setParent(this);
  DisplaySourceFilesButton->setText("S");
  DisplaySourceFilesButton->move(25, 1);
  DisplaySourceFilesButton->resize(24,24);
  connect(DisplaySourceFilesButton, SIGNAL(pressed()), this, SLOT(SlotDisplaySourceFilesButtonPushed()));

  //! Create the DisplayTargetsButton button
  DisplayTargetsButton = new QPushButton();
  DisplayTargetsButton->setParent(this);
  DisplayTargetsButton->setText("T");
  DisplayTargetsButton->move(50, 1);
  DisplayTargetsButton->resize(24,24);
  connect(DisplayTargetsButton, SIGNAL(pressed()), this, SLOT(SlotDisplayTargetsButtonPushed()));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleToolBar::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleToolBar::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : SlotDisplayModulesButtonPushed
 *****************************************************************************/
void
ModuleToolBar::SlotDisplayModulesButtonPushed(void)
{
  emit SignalDisplayModules();
}

/*****************************************************************************!
 * Function : SlotDisplaySourceFilesButtonPushed
 *****************************************************************************/
void
ModuleToolBar::SlotDisplaySourceFilesButtonPushed(void)
{
  emit SignalDisplaySource();
}

/*****************************************************************************!
 * Function : SlotDisplayTargetsButtonPushed
 *****************************************************************************/
void
ModuleToolBar::SlotDisplayTargetsButtonPushed(void)
{
  emit SignalDisplayTargets();
}
