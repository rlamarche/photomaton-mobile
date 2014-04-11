package com.rlamarche.photomaton_mobile;

import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;

import org.qtproject.qt5.android.bindings.QtActivity;

import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.hardware.usb.UsbDevice;
import android.hardware.usb.UsbDeviceConnection;
import android.hardware.usb.UsbManager;
import android.os.Bundle;

public class MainActivity extends QtActivity {
	
	private UsbManager mUsbManager;
	private PendingIntent mPermissionIntent;
	private static final String ACTION_USB_PERMISSION =
		    "com.android.example.USB_PERMISSION";

	private static boolean loaded = false;
	public static synchronized void loadNativeLibraries() {
		if (!loaded) {
			final String[] libs = new String[]{
					"exif2", "ltdl", "regex", "usb2", 
					"gphoto2_port", "gphoto2"//, "usb-compat"
			};
			for (final String lib : libs) {
				System.loadLibrary(lib);
			}
			loaded = true;
		}
	}
	
	static {
		loadNativeLibraries();
	}

	
	@Override
	public void onCreate(final Bundle savedInstanceState) {
		mUsbManager         = (UsbManager) getSystemService( Context.USB_SERVICE );
	    HashMap< String, UsbDevice > stringDeviceMap    =       mUsbManager.getDeviceList();
	    Collection< UsbDevice > usbDevices              = stringDeviceMap.values();

	    mPermissionIntent = PendingIntent.getBroadcast(this, 0, new Intent( ACTION_USB_PERMISSION ), 0 );

	    Iterator< UsbDevice > usbDeviceIter             = usbDevices.iterator();
	    while( usbDeviceIter.hasNext() )
	    {
	    	UsbDevice usbDevice = usbDeviceIter.next();
	     //   if ( usbDevice.getVendorId() == 0x04b0 && usbDevice.getProductId() == 0x042a )
	      //  {
	            // Request permission to access the device.
	            mUsbManager.requestPermission( usbDevice, mPermissionIntent );
	     //   }
	    }
	    super.onCreate(savedInstanceState);
	}
}
