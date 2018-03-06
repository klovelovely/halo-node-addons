### 尝试 Node.js 的 C++ 插件
参考: http://nodejs.cn/api/addons.html

`node-addon-halo-allo.cc` 为即将用来编译的插件源码(编译成二进制 `xxx.node` 文件), `binding.gyp` 用来描述模块的构建配置的文件, node-gyp 会使用这个配置文件进行编译构建.

1. 安装 Node.js 插件编译工具 `node-gyp`
```
npm install -g node-gyp
```

2. 使用 `node-gyp configure` 为当前平台生成相应的项目构建文件.  这会在 `build/` 目录下生成一个 Makefile 文件（在 Unix 平台上）或 vcxproj 文件（在 Windows 上）
```
node-gyp configure
```

3. 调用 `node-gyp build` 命令生成编译后的 `addon.node` 的文件。 它会被放进 build/Release/ 目录。
```
node-gyp build
```

当构建完成时，二进制插件就可以在 Node.js 中被使用，通过 `require()` 构建后的 `addon.node` 模块：
```
// hello.js
const addon = require('./build/Release/addon');

console.log(addon.hello());
// 打印: 'world'
```