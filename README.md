项目2：智能手表

项目简历：
基于Qt的智能手表，通过设计模式中的策略模式，使用QStackedWidget的控件，添加了英汉互译、天气预报、ai问答搜索、秒表、计算器，
使用信号与槽点击对应按钮来实现切换应用，使用QSettings类实现 使用应用的数据 持久化保存，可一键清空。

技术栈：
1.C++/Qt。
2.Qt Network (使用QNetworkAccessManager类对象的get()/post())。
3.https/http，通过QJsonDocument/QJsonObject/QJsonArray类来解析提取网站返回的JSON数据。
4.设计模式当中的策略模式。

功能特点：
1.使用的策略模式，后续只需要单独写好功能更容易添加到QStackedWidget控件里，封装不同的业务模块。
2.英汉互译、天气预报、ai问答（使用硅基流动API）
3.基本的看时间、秒表、计算器功能。








