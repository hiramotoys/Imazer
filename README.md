Imazer
======
Naoのカメラパラメータを簡単に設定できるツール


使い方
-------------
Qt4
MacならMacPortsでインストールできる
	sudo port install qt4-mac

NAO SDK
好きな場所に置いてやる. bashrcやzshrc環境変数を設定する. 
例えば、
	export AL_DIR=/Users/hiramotoys/nao_sdk

コンパイルについて
Macなら、
	qmake -spec macx-g++40
qmakeでMakefileが生成される.
んで
	make
でコンパイルできる.

起動はImazer.appをダブルクリックしたり、
	open -a Imazer.app
もしくは
	Imazer.app/MacOS/Contents/Imazer

WindowsやLinuxでも動くはず(未確認).