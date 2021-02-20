# stopWatch

picoEV用に開発したラップタイムを記録するプログラムです
## needs

+M5Stack
+microSD カード

microSD カードにラップタイムを記録させることができる．データは```rapcount```, ```minute```, ```second```, ```microsecond```の順に書き込まれる
例
```
number,min,second,msRap
1,0,07,346
2,0,35,262
3,1,12,115
...
```

## usage
まずはユーザーディレクトリにクローンさせる

```
git clone 
cd stopWatch
```

次に，Arduino IDE で書込みを行う．M5Stackを利用するには専用のUSBドライバとライブラリをインストールする必要があるが，ここでは割愛させていただく

プログラムを実行させる前にSDカードを挿入させる必要がある
