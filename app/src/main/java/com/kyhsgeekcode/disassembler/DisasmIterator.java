package com.kyhsgeekcode.disassembler;
import android.app.*;
import java.util.*;

public class DisasmIterator extends AssemblyProvider
{
    //<<<<<<< HEAD
    //<<<<<<< HEAD
    //public DisasmIterator(MainActivity activity,
    //						//NotificationManager mNotifyManager,
    //						//Notification.Builder mBuilder,
    //						ListViewAdapter adapter,
    //						long total)
    //=======
    //public DisasmIterator(MainActivity activity, NotificationManager mNotifyManager, Notification.Builder mBuilder, ListViewAdapter adapter,  long total)
    //>>>>>>> parent of 2644076... Update readme with assembly materials links
    //=======
    public DisasmIterator(MainActivity activity,/* NotificationManager mNotifyManager, Notification.Builder mBuilder, */ListViewAdapter adapter,  long total)
    //>>>>>>> parent of 2644076... Update readme with assembly materials links
    {
        super(activity, adapter, total);
    }
    public native long getAll(byte[] bytes, long offset, long size, long virtaddr/*,ArrayList<ListViewItem> arr*/);
    public native long getSome(byte[] bytes, long offset, long size, long virtaddr, int count/*,ArrayList<ListViewItem> arr*/);

    public int showNoti(int progress)
    {
        //mBuilder.setProgress((int)total,progress, false);
        // Displays the progress bar for the first time.
        //mNotifyManager.notify(0, mBuilder.build());
        //activity.runOnUiThread(activity.runnableRequestLayout);
        if(Thread.interrupted())
        {
            return -1;
        }
        return 0;
    }
    public native int CSoption(int type, int vslue);
}
