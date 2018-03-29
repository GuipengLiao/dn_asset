
# Unity 实现Avatar换装

<img src="https://huailiang.github.io/img/in-post/post-fashion/fashion1.gif">

## 提取资源-预处理

### 第一步： 从fbx中提取部件mesh, 并给mesh赋值一些必要的属性

### 第二步： 保存mesh, 并提取出Main Texture,并且保存在本地

### 第三步： 预处理uv
根据部件位置序列，设置相应uv, 先确保uv的区间在[0,1]之间，然后u加上部件的索引 uvOffsetX对应每个部位的枚举定义值[1-8], 至于为什么这么处理，我们对在后面shader中使用这些uv信息，拼接时装时会用到。

往往在预处理uv之前，为了减少不必要的计算和内存，也是为了优化，我们会清理掉mesh上可能附带的信息，比如uv2，切线信息。

 处理好的之后的mesh 确保是干净的，且只有我们想要的信息。如下图所示，只有第一层uv和skin信息，并没有其他冗余的信息。所有都处理好之后，我们可以写批处理脚本，把所有的资源都移到程序所用的工程Rsources目录下。

<img src="https://huailiang.github.io/img/in-post/post-fashion/fashion2.jpg"/>

 ### 第四步： 预处理Texture
 在Texture提取出来之后，往往是各种预带有各种信息，这时我们还需要写一个类似格式刷工具把项目里所有的texture全部处理一遍。类似这样实现：

## 运行时，组装时装

### 第一步：Shader处理， DrawCall合并

这时游戏中参与光照计算的shader,由八张Texture合并。 Shader针对预处理的uv拼接时装。
下面代码会在MaskNV函数会在vert Shader中调用，BlendColor函数在frag 函数中调用。

### 第二步 c#动态拼接
- 收集部件
- 合并skinmesh
- 设置材质
- 设置texture

在设置texture的时候我们使用MaterialPropertyBlock做了优化，更多关于MaterialPropertyBlock的知识，可以参考下面一篇文章：
[使用MaterialPropertyBlock来替换Material属性操作][i1]

还要说明的是部件的骨骼，再合成新的skinmesh之后，骨骼节点还是对动画animation保留的，对于网上很多教程在合并前保存部件的骨骼节点，合成之后再赋值给skinmesh完全是没必要的，以免带来不必要的计算和内存开销。
