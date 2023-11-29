QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

QMAKE_LFLAGS_WINDOWS            += -mwindows

QMAKE_CXXFLAGS                  += 

QMAKE_LIBS                      = 

TARGET                          = CodeMerge

VERSION                         = "0.0.0"
QMAKE_TARGET_COMPANY            = "Greg Saltis"

QMAKE_TARGET_PRODUCT            = "CodeMerge"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Greg Saltis"

QT                              += core gui widgets

DEFINES                         += \

SOURCES                         += \
				   MainControlBar.cpp                           \
				   MainDisplayWindow.cpp                        \
				   MainMessageWindow.cpp                        \
				   MainSettings.cpp                             \
				   MainWindow.cpp                               \
				   MainWindowHeader.cpp                         \
				   ModuleWindow.cpp                             \
				   SystemConfig.cpp                             \
				   TrackViewWindow.cpp                          \
				   main.cpp                                     \

HEADERS                         += \
				   MainControlBar.h                             \
				   MainDisplayWindow.h                          \
				   MainMessageWindow.h                          \
				   MainSettings.h                               \
				   MainWindow.h                                 \
				   MainWindowHeader.h                           \
				   ModuleWindow.h                               \
				   SystemConfig.h                               \
				   TrackViewWindow.h                            \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = 
cleanall.depends                = junkclean                                     \
                                  clean
