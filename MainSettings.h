/*****************************************************************************
 * FILE NAME    : MainSettings.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainsettings_h_
#define _mainsettings_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainSettings
 *****************************************************************************/
class MainSettings : public QSettings
{
  Q_OBJECT;

 //! Constructors
 public :
  MainSettings                  (QString InOrgName, QString InAppName);

 //! Destructor
 public :
  ~MainSettings                 ();

 //! Public Methods
 public :
  void                          GetMainWindowGeometry   (QPoint &InPosition, QSize &InSize);
  void                          SetMainWindowGeometry   (QPoint InPosition, QSize InSize);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _mainsettings_h_*/
