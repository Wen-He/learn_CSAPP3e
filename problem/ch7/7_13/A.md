A.

    whereis

    ar -t 

# on my machine

# ar -t /usr/lib/x86_64-linux-gnu/libm.a
# ar: /usr/lib/x86_64-linux-gnu/libm.a: 不可识别的文件格式

# file /usr/lib/x86_64-linux-gnu/libm.a
# /usr/lib/x86_64-linux-gnu/libm.a: ASCII text
# gedit /usr/lib/x86_64-linux-gnu/libm.a

# ar t /usr/lib/x86_64-linux-gnu/libm-2.27.a        // produce the ideal result