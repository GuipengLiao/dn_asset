ABϵͳ��

1.  �Լ�ά��ʵ��������ϵ û��ʹ��U5������

2.  ����������ϵ���ݹ������ȼ�������->�ټ��ر���
	������������prefab���ȰѶ�Ӧ����������Դ����Texture����load��ȥ��Ȼ��Load Prefab�� ����prefab�ϰ�(����)����Դ���Զ���Ӧ��prefab
	��Ȼ����ab��ʱ��Ҫ�Ƚ�prefab����������Դ�⿪������ᵼ��ab����

3.  �Լ�ʵ��XAssetBundle U5���س�����bundle��������ж�� ��˵һ��texture��Ӧ��bundle unload֮��textureҲ�ᱻж�� Ҫ�ȴ�һ��ʱ�����ȥж��
	������������Դ��ò�Ҫж�أ���Ϊ����������Դ��Ҫ���ص�ʱ��bundle��Ҫ�ٴ�load��������Դ��abж��ѡ��ǡ����ʱ��������˵�г���
	��Ϊ������������Դ��ж�أ�������ڴ�����ߣ���������Ƶ�ʱ�򣬾�������������
	�����ٴ�ab��ʱ���ֶ��Ľ�����������ʱ�Զ���ά��������ϵ������ʹ��unity�Դ�������ά��

4.  ���Asset-Object ����Cloned-Object��ж�أ�bundle.loadasset�����Ķ��󣬶���Instantiate��
	���������GameObject �ڱ༭��ģʽ���޷�ж��go���壬����ᱨ���ø���DestroyImmediate(obj, true) �����������ļ������ԭʼAssetһ��ɾ��
	���������Texture��Material��ʹ��Resources.UnloadAsset��, ����Ȼ�������ø�ͼ����ô����ͱ�ȫ��
 
5.  �����������̺ͳ��򹤳̷ֿ������򹤳�û��ԭʼ����Դ�����Ƕ����ƣ�����avatar,ui, scene�ȡ�����������ԭʼ��Դת��ab�Ĺ��ߣ����򹤳�����������ʱ��Ͳ���ÿ�ζ���ab 
	��Դab������ά��

6.  Object��������������ʽת�������== �������null�Ƚ�ʱҪ�ر�ע�⣬��ʹ����Ч�����ý���п�����true��
	GameObject go = new GameObject(); 
	Debug.Log (go == null); // false

	Object obj = new Object();
	Debug.Log (obj == null); // true

	Instatiating a GameObject adds it to the scene so it is completely initialized (!destroyed). Instantiating a simple UnityEngine.Object has no such semantics, so the it stays in the 'destroyed' state which compares true to null.

