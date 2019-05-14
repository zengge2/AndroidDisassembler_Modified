package com.kyhsgeekcode.disassembler;

import android.app.*;
import android.content.*;
import android.view.*;
import android.widget.*;
import com.skydoves.colorpickerview.*;
import com.skydoves.colorpickerview.listeners.*;

public class ColorPrefLvAdapter extends BaseAdapter
{
    // Adapter? ??? ???? ???? ?? ArrayList
    Enum[] rows;
    Palette palette;
    Context c;
    // ListViewAdapter? ???
    public ColorPrefLvAdapter(Palette pal, Context c)
    {
        palette = pal;
        rows = pal.getRows();
        this.c = c;
    }

    // Adapter? ???? ???? ??? ??. : ?? ??
    @Override
    public int getCount()
    {
        return rows.length;
    }

    // position? ??? ???? ??? ????? ??? View? ??. : ?? ??
    @Override
    public View getView(int position, View convertView, ViewGroup parent)
    {
        //  final int pos = position;
        final Context context = parent.getContext();

        // "listview_item" Layout? inflate?? convertView ?? ??.
        if (convertView == null)
        {
            LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.colorpref_itemrow, parent, false);
        }

        // ??? ??? View(Layout? inflate?)???? ??? ?? ?? ??
        TextView rowname = (TextView) convertView.findViewById(R.id.colorPrefRowName) ;
        Enum listViewItem = rows[position];
        rowname.setText(listViewItem.name());
        Button btTxtColor = (Button) convertView.findViewById(R.id.colorprefitemrowButtonText);
        btTxtColor.setBackgroundColor(palette.getTxtColor(listViewItem));
        Button btBkColor = (Button)convertView.findViewById(R.id.colorprefitemrowButtonBk);
        btBkColor.setBackgroundColor(palette.getBkColor(listViewItem));
        btTxtColor.setOnClickListener(new ColorBtnListener(listViewItem, btTxtColor, 0));
        btBkColor.setOnClickListener(new ColorBtnListener(listViewItem, btBkColor, 1));
        return convertView;
    }

    // ??? ??(position)? ?? ???? ??? ???(row)? ID? ??. : ?? ??
    @Override
    public long getItemId(int position)
    {
        return position ;
    }

    // ??? ??(position)? ?? ??? ?? : ?? ??
    @Override
    public Object getItem(int position)
    {
        return rows[position];
    }
    class ColorBtnListener implements View.OnClickListener
    {
        Enum item;
        Button button;
        int mode;
        public ColorBtnListener(Enum item, Button bt, int mode)
        {
            this.item = item;
            button = bt;
            this.mode = mode;
        }
        @Override
        public void onClick(View p1)
        {
            ColorPickerDialog.Builder builder = new ColorPickerDialog.Builder(c, AlertDialog.THEME_DEVICE_DEFAULT_DARK);
            builder.setTitle(item.name());
            //builder.setFlagView(new CustomFlag(this, R.layout.layout_flag));
            builder.setPositiveButton(/*getString(R.string.confirm)*/"OK", new ColorEnvelopeListener()
            {
                @Override
                public void onColorSelected(ColorEnvelope envelope, boolean fromUser)
                {
                    //setLayoutColor(envelope);
                    button.setBackgroundColor(envelope.getColor());
                    if(mode == 0)
                        palette.setTxtColor(item, envelope.getColor());
                    else
                        palette.setBkColor(item, envelope.getColor());
                }
            });
            builder.setNegativeButton(/*getString(R.string.cancel)*/"Cancel", new DialogInterface.OnClickListener()
            {
                @Override
                public void onClick(DialogInterface dialogInterface, int i)
                {
                    dialogInterface.dismiss();
                }
            });
            //builder.attachAlphaSlideBar(); // attach AlphaSlideBar
            builder.attachBrightnessSlideBar(); // attach BrightnessSlideBar
            builder.show(); // show dialog
            //	builder.setPreferenceName("MyColorPickerDialog");
            return;
        }

    }
}
//http://recipes4dev.tistory.com/m/43
