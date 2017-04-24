package com.example.test;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity{
	static {
        System.loadLibrary("test");
    }
	private native String nativeMalloc();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		long maxMemory = Runtime.getRuntime().maxMemory();
		System.out.println("heapSizeMax(B)->" + maxMemory);
		System.out.println("heapSizeMax(MB)->" + maxMemory/1024/1024 + "M");
		byte[] b = new byte[58  * 1024 * 1024];
		nativeMalloc();
	}
}
