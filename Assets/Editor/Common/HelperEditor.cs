//
// EditorHelper.cs
// Created by huailiang.peng on 2016/03/18 11:20:38
//

using UnityEngine;
using UnityEditor;
using System.IO;

public class HelperEditor : MonoBehaviour 
{

	public static string basepath
	{
		get
		{
			string path=Application.dataPath;
			path =path.Remove(path.IndexOf("/Assets"));
			return path;
		}
	}
    
    [MenuItem("Help/IO/OpenCacheDiectory")]
	public static void OpenCacheDiectory()
	{
		Open(Application.temporaryCachePath);
	}

    [MenuItem("Help/IO/OpenPersistDirectory")]
    public static void OpenPersistDirectory()
    {
        Open(Application.persistentDataPath);
    }


    [MenuItem("Help/IO/OpenShellDirectory")]
	public static void OpenAssetbundle()
	{
		Open(basepath+"/Shell");
	}

    [MenuItem("Help/IO/OpenUnityInstallDirectory")]
    public static void OpenUnityDir()
    {
        Open(EditorApplication.applicationContentsPath);
    }

    [MenuItem("Help/IO/CleanCache")]
	public static void CleanCache()
	{
		Caching.CleanCache();
        int isShow = PlayerPrefs.GetInt("ShowWelcomeScreen", 1);
        XDebug.Log("Do Cache "+isShow);
	}

    [MenuItem("Help/IO/PlayerPrefsDeleteAll")]
	public static void PlayerPrefsDeleteAll()
	{
		PlayerPrefs.DeleteAll();
	}

	public static void Open(string path)
	{
        XDebug.Log("Open:", path);
        if(File.Exists(path))
        {
            path = Path.GetDirectoryName(path);
        }
        if (!Directory.Exists(path))
        {
            Directory.CreateDirectory(path);
        }
#if UNITY_EDITOR_OSX
		string shell =basepath+"/Shell/open.sh";
//		Debug.Log("shell: "+shell+" exist: "+System.IO.File.Exists(shell));
		string arg= path;
		string ex=shell+" "+arg;
		System.Diagnostics.Process.Start("/bin/bash", ex);
#elif UNITY_EDITOR_WIN
        path = path.Replace("/", "\\");
        System.Diagnostics.Process.Start("explorer.exe", path);
#endif
	}
}
