
	GXT HOOK for San Andreas

	22/08/07

----------------------------------------------------------------------------------------


1. This is a CLEO library plugin. This plugin allows using custom texts in your scripts 
without modifying the GXT files. 

2. To add new text entries, create a file with extension �.fxt� and place it in the 
�GTASA\CLEO\cleo_text� folder. The file has to contain a list of new entries in the 
following format:

<ENTRY NAME><space><TEXT>

Each line must contain only one entry. An entry name is limited to 7 characters 
(as in a GXT). After it, there should be a SINGLE space, and then a custom text.
Anything written after single space until the end of the line is considered as a 
custom text assigned to the GXT entry.

3. You may add as many lines (entries) as you wish. Name of the .fxt file does 
not matter. You can add unlimited number of such files, even one GXT entry per file.

4. To comment out a line, use symbols ; or # in the beginning of the line.

5. To use new text in game, use the GXT entry as usual. For example, if you add a 
line:

MYMOD Take a car!

in a fxt file, you can display this text in game using opcode 03E5:

03E5: show_text_box �MYMOD�

6. To make this plugin work, the CLEO library must be installed. You may find newest 
version of this library and other plugins on cleo.sannybuilder.com


----------------------------------------------------------------------------------------


1. ����� ���� ������ ��� ���������� CLEO. ���� ������ ��������� ������������ 
����������� ������ � ����� �������� ��� ��������� GXT ������.

2. ����� �������� ����� ������, �������� ���� � ����������� �.fxt� � ��������� ��� � ����� 
�GTASA\CLEO\cleo_text�. ���� ������ ��������� ������ ����� ����� ������ � ��������� �������:

<���><������><�����>

������ ������ ������ ��������� ������ ���� ������. ��� ������ ���������� ����� ������� 
(��� � GXT). ����� ���� ������ ������ ���� ������, ����� ����� �����. ���, ��� �������� 
����� ������� �� ����� ������, ��������������� ��� ����� � ������ ������.

3. �� ������ ��������� ������� ������ ����� (�������). ��� fxt-����� �� ����� ��������. 
�� ������ ��������� �������������� ����� ������, ���� �� ������ ����� �� ������ ������.

4. ����� ���������������� ������ ����������� ������� ; ��� # � ������ ������.

5. ����� ������������ ����� ����� � ����, ����������� ��� GXT ������ ��� ������. 
��������, ���� �� �������� ������

MYMOD Take a car!

� fxt-����, �� ������ �������� ��� � ����, ��������� ����� 03E5:

03E5: show_text_box �MYMOD�

����� ������������ � ������� �������, ��� ����� ��� ����������� ����������� ��������� 
��� �������� �������� ������ � ����������, ���������� �����. �� ������ ����� ����� 
��������� �� yelmi.narod.ru

6. ����� ������ �������, �� ������ ���������� ���������� CLEO. ����� ������ ������ ����� 
����� �� ����� cleo.sannybuilder.com


----------------------------------------------------------------------------------------

 � 2007 Seemann
 sannybuilder.com

