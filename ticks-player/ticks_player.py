# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.4.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setWindowModality(QtCore.Qt.WindowModal)
        MainWindow.resize(800, 500)
        self.central_widget = QtWidgets.QWidget(MainWindow)
        self.central_widget.setObjectName("central_widget")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.central_widget)
        self.horizontalLayout_2.setContentsMargins(11, 11, 11, 11)
        self.horizontalLayout_2.setSpacing(6)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setContentsMargins(11, 11, 11, 11)
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout_2.setSpacing(6)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout.setSpacing(6)
        self.verticalLayout.setObjectName("verticalLayout")
        self.vertical_layout_3 = QtWidgets.QVBoxLayout()
        self.vertical_layout_3.setContentsMargins(11, 11, 11, 11)
        self.vertical_layout_3.setSpacing(6)
        self.vertical_layout_3.setObjectName("vertical_layout_3")
        self.mode_label = QtWidgets.QLabel(self.central_widget)
        self.mode_label.setObjectName("mode_label")
        self.vertical_layout_3.addWidget(self.mode_label)
        self.mode_combobox = QtWidgets.QComboBox(self.central_widget)
        self.mode_combobox.setObjectName("mode_combobox")
        self.vertical_layout_3.addWidget(self.mode_combobox)
        self.verticalLayout.addLayout(self.vertical_layout_3)
        self.mode_go_push_button = QtWidgets.QPushButton(self.central_widget)
        self.mode_go_push_button.setObjectName("mode_go_push_button")
        self.verticalLayout.addWidget(self.mode_go_push_button)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout.addItem(spacerItem)
        self.vertical_layout_4 = QtWidgets.QVBoxLayout()
        self.vertical_layout_4.setContentsMargins(11, 11, 11, 11)
        self.vertical_layout_4.setSpacing(6)
        self.vertical_layout_4.setObjectName("vertical_layout_4")
        self.view_label = QtWidgets.QLabel(self.central_widget)
        self.view_label.setObjectName("view_label")
        self.vertical_layout_4.addWidget(self.view_label)
        self.view_combobox = QtWidgets.QComboBox(self.central_widget)
        self.view_combobox.setObjectName("view_combobox")
        self.vertical_layout_4.addWidget(self.view_combobox)
        self.verticalLayout.addLayout(self.vertical_layout_4)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        self.indicators_group = QtWidgets.QGroupBox(self.central_widget)
        self.indicators_group.setObjectName("indicators_group")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.indicators_group)
        self.verticalLayout_3.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout_3.setSpacing(6)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.vertical_layout_7 = QtWidgets.QVBoxLayout()
        self.vertical_layout_7.setContentsMargins(11, 11, 11, 11)
        self.vertical_layout_7.setSpacing(6)
        self.vertical_layout_7.setObjectName("vertical_layout_7")
        self.vertical_layout = QtWidgets.QVBoxLayout()
        self.vertical_layout.setContentsMargins(11, 11, 11, 11)
        self.vertical_layout.setSpacing(6)
        self.vertical_layout.setObjectName("vertical_layout")
        self.on_graph_label = QtWidgets.QLabel(self.indicators_group)
        self.on_graph_label.setObjectName("on_graph_label")
        self.vertical_layout.addWidget(self.on_graph_label)
        self.on_graph_combobox = QtWidgets.QComboBox(self.indicators_group)
        self.on_graph_combobox.setObjectName("on_graph_combobox")
        self.vertical_layout.addWidget(self.on_graph_combobox)
        self.vertical_layout_7.addLayout(self.vertical_layout)
        self.vertical_layout_2 = QtWidgets.QVBoxLayout()
        self.vertical_layout_2.setContentsMargins(11, 11, 11, 11)
        self.vertical_layout_2.setSpacing(6)
        self.vertical_layout_2.setObjectName("vertical_layout_2")
        self.off_graph_label = QtWidgets.QLabel(self.indicators_group)
        self.off_graph_label.setObjectName("off_graph_label")
        self.vertical_layout_2.addWidget(self.off_graph_label)
        self.off_graph_combobox = QtWidgets.QComboBox(self.indicators_group)
        self.off_graph_combobox.setObjectName("off_graph_combobox")
        self.vertical_layout_2.addWidget(self.off_graph_combobox)
        self.vertical_layout_7.addLayout(self.vertical_layout_2)
        self.verticalLayout_3.addLayout(self.vertical_layout_7)
        self.verticalLayout_2.addWidget(self.indicators_group)
        self.start_refresh_button = QtWidgets.QPushButton(self.central_widget)
        self.start_refresh_button.setObjectName("start_refresh_button")
        self.verticalLayout_2.addWidget(self.start_refresh_button)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout_2.addItem(spacerItem1)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.chart_group = QtWidgets.QGroupBox(self.central_widget)
        self.chart_group.setObjectName("chart_group")
        self.horizontalLayout.addWidget(self.chart_group)
        self.horizontalLayout.setStretch(0, 1)
        self.horizontalLayout.setStretch(1, 5)
        self.horizontalLayout_2.addLayout(self.horizontalLayout)
        MainWindow.setCentralWidget(self.central_widget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Ticks Player"))
        self.mode_label.setText(_translate("MainWindow", "Mode"))
        self.mode_go_push_button.setText(_translate("MainWindow", "Go"))
        self.view_label.setText(_translate("MainWindow", "View"))
        self.indicators_group.setTitle(_translate("MainWindow", "Indicators"))
        self.on_graph_label.setText(_translate("MainWindow", "On Graph"))
        self.off_graph_label.setText(_translate("MainWindow", "Off Graph"))
        self.start_refresh_button.setText(_translate("MainWindow", "Start/Refresh"))
        self.chart_group.setTitle(_translate("MainWindow", "Chart"))

