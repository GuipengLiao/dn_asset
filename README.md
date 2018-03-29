
# Unity 实现Avatar换装

对应CutScene.unity

<img src="https://huailiang.github.io/img/in-post/post-fashion/fashion1.gif">

## 提取资源-预处理

### 第一步： 从fbx中提取部件mesh, 并给mesh赋值一些必要的属性

### 第二步： 保存mesh, 并提取出Main Texture,并且保存在本地

### 第三步： 预处理uv
根据部件位置序列，设置相应uv, 先确保uv的区间在[0,1]之间，然后u加上部件的索引 uvOffsetX对应每个部位的枚举定义值[1-8]。

往往在预处理uv之前，为了减少不必要的计算和内存，也是为了优化，我们会清理掉mesh上可能附带的信息，比如uv2，切线信息。处理好的之后的mesh确保是干净的，且只有我们想要的信息。

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



# AI 系统

对应AI.unity

Behavior Designer 是一个行为树插件！是为了让设计师，程序员，美术人员方便使用的可视化编辑器！Behavior Designer 提供了强大的 API 可以让你轻松的创建 tasks（任务），配合 uScript 和 PlayMaker 这样的插件，可以不费吹灰之力就能够创建出强大的 AI 系统，而无需写一行代码！

如果你还不了解什么是行为树（behavior trees）请查看"行为树的概述"！依赖于 Behavior Designer你完全可以不用关心什么是行为树（behavior trees）但是，如果你了解了一些 behavior trees！这将有助于你使用 Behavior Designer，包括一些常用组件，例如：tasks（任务），action（行为），composite（复合），conditional（条件），decorator（修饰符）!

![](/img/ai.gif)


# 过场动画

对应CutScene.unity

![](/img/cutscene.gif)

基于帧实现的一套战斗动画 cutscene. 

打开 cutscene编辑器，点击 XEditor->Cutscene

你可以在编辑器里编辑特效、文字、声音、动画等

![](/img/cutscene.jpg)






