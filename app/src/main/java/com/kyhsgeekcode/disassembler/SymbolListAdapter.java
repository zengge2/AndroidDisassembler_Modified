package com.kyhsgeekcode.disassembler;


import android.content.*;
import android.util.*;
import android.view.*;
import android.widget.*;
import java.util.*;

public class SymbolListAdapter extends BaseAdapter
{
    // Adapter? ??? ???? ???? ?? ArrayList
    private ArrayList<Symbol> listViewItemList = new ArrayList<>() ;

    private String TAG = "Disassembler sym";

    public SymbolListAdapter()
    {

    }

    public void addAll(List<Symbol> symbols)
    {
        Log.d(TAG, "addall sym calls len=" + symbols.size());
        listViewItemList.addAll(symbols);
        notifyDataSetChanged();
        return ;
    }
    //You should not modify
    public ArrayList<Symbol> itemList()
    {
        return listViewItemList;
    }

    // Adapter? ???? ???? ??? ??. : ?? ??
    @Override
    public int getCount()
    {
        return listViewItemList.size() ;
    }

    // position? ??? ???? ??? ????? ??? View? ??. : ?? ??
    @Override
    public View getView(int position, View convertView, ViewGroup parent)
    {
        final int pos = position;
        final Context context = parent.getContext();

        // "listview_item" Layout? inflate?? convertView ?? ??.
        if (convertView == null)
        {
            LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.symbol_row, parent, false);
        }

        // ??? ??? View(Layout? inflate?)???? ??? ?? ?? ??
        TextView addrTextView = (TextView) convertView.findViewById(R.id.symbolrowTVaddress) ;
        TextView mangledTextView = (TextView) convertView.findViewById(R.id.symbolrowTVmangled) ;
        TextView demangledTextView = (TextView) convertView.findViewById(R.id.symbolrowTVdemangled) ;
        TextView propTextView = (TextView) convertView.findViewById(R.id.symbolrowTVprop) ;

        {
            // Data Set(listViewItemList)?? position? ??? ??? ?? ??
            Symbol listViewItem = listViewItemList.get(position);

            addrTextView.setText(Long.toHexString( listViewItem.st_value));
            mangledTextView.setText(listViewItem.name);
            demangledTextView.setText(listViewItem.demangled);
            try
            {
                propTextView.setText(listViewItem.bind.toString() + listViewItem.type.toString());
            }
            catch(NullPointerException e)
            {

            }
        }
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
        return listViewItemList.get(position) ;
    }

    // ??? ??? ??? ?? ??. ???? ????? ?? ??.
    public void addItem(Symbol item)
    {
        listViewItemList.add(item);
        //notifyDataSetChanged();
    }
}
//http://recipes4dev.tistory.com/m/43
