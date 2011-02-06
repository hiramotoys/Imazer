# Imazer
Naoのカメラパラメータを簡単に設定できるツール


#環境構築

## Qt4をインストール

### Mac
MacPortsでインストールできる
	sudo port install qt4-mac +universal

## NAO SDK
### Mac, Linux
好きな場所に置いてやる.  
bashrcやzshrc環境変数AL_DIRを設定する.  
例えば、
	export AL_DIR=/Users/hiramotoys/nao_sdk



# コンパイルについて

## Mac(Snow Leopard)
	qmake -spec macx-g++40
qmakeでMakefileが生成される.
	make
でコンパイルできる.

起動はImazer.appをダブルクリックしたり、
	open -a Imazer.app
もしくは
	Imazer.app/MacOS/Contents/Imazer

## Linux(動作未確認)
qmakeしてmakeすれば動くはず

## Windows(動作未確認)