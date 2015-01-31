<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Dash parts">
<packages>
<package name="SOIC8">
<description>&lt;B&gt;Wide Plastic Gull Wing Small Outline Package&lt;/B&gt;</description>
<wire x1="-2.6" y1="2.25" x2="-2.35" y2="2.5" width="0.1524" layer="21" curve="-90"/>
<wire x1="2.35" y1="2.5" x2="2.6" y2="2.25" width="0.1524" layer="21" curve="-90"/>
<wire x1="2.35" y1="-2.5" x2="2.6" y2="-2.25" width="0.1524" layer="21" curve="90"/>
<wire x1="-2.6" y1="-2.25" x2="-2.35" y2="-2.5" width="0.1524" layer="21" curve="90"/>
<wire x1="2.36" y1="-2.5" x2="-2.34" y2="-2.5" width="0.1524" layer="51"/>
<wire x1="-2.34" y1="2.5" x2="2.36" y2="2.5" width="0.1524" layer="51"/>
<wire x1="-2.21" y1="2.5" x2="-2.34" y2="2.5" width="0.1524" layer="21"/>
<wire x1="-1.59" y1="2.5" x2="-0.95" y2="2.5" width="0.1524" layer="21"/>
<wire x1="-0.32" y1="2.5" x2="0.32" y2="2.5" width="0.1524" layer="21"/>
<wire x1="0.95" y1="2.5" x2="1.59" y2="2.5" width="0.1524" layer="21"/>
<wire x1="2.21" y1="2.5" x2="2.36" y2="2.5" width="0.1524" layer="21"/>
<wire x1="2.2" y1="-2.5" x2="2.33" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="1.59" y1="-2.5" x2="0.94" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="0.32" y1="-2.5" x2="-0.33" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="-0.95" y1="-2.5" x2="-1.59" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="-2.21" y1="-2.5" x2="-2.34" y2="-2.5" width="0.1524" layer="21"/>
<wire x1="-2.6" y1="2.25" x2="-2.6" y2="-2.24" width="0.1524" layer="21"/>
<wire x1="2.6" y1="-2.25" x2="2.6" y2="2.25" width="0.1524" layer="21"/>
<circle x="-1.42" y="-1.115" radius="0.5" width="0.0508" layer="21"/>
<smd name="1" x="-1.905" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="2" x="-0.645" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="3" x="0.625" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="4" x="1.895" y="-3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="8" x="-1.905" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="7" x="-0.635" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="6" x="0.635" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<smd name="5" x="1.905" y="3.154" dx="0.5" dy="2.2" layer="1"/>
<text x="-2.8575" y="-2.159" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="4.064" y="-2.159" size="1.27" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.08" y1="2.5" x2="-1.73" y2="3.4" layer="51"/>
<rectangle x1="-0.81" y1="2.5" x2="-0.46" y2="3.4" layer="51"/>
<rectangle x1="0.46" y1="2.5" x2="0.81" y2="3.4" layer="51"/>
<rectangle x1="1.73" y1="2.5" x2="2.08" y2="3.4" layer="51"/>
<rectangle x1="1.72" y1="-3.4" x2="2.07" y2="-2.5" layer="51"/>
<rectangle x1="0.45" y1="-3.4" x2="0.8" y2="-2.5" layer="51"/>
<rectangle x1="-0.82" y1="-3.4" x2="-0.47" y2="-2.5" layer="51"/>
<rectangle x1="-2.08" y1="-3.4" x2="-1.73" y2="-2.5" layer="51"/>
</package>
<package name="R0805">
<description>&lt;b&gt;RESISTOR&lt;/b&gt;&lt;p&gt;
chip</description>
<wire x1="-0.41" y1="0.635" x2="0.41" y2="0.635" width="0.1524" layer="51"/>
<wire x1="-0.41" y1="-0.635" x2="0.41" y2="-0.635" width="0.1524" layer="51"/>
<wire x1="-1.973" y1="0.983" x2="1.973" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="0.983" x2="1.973" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="-0.983" x2="-1.973" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-1.973" y1="-0.983" x2="-1.973" y2="0.983" width="0.0508" layer="39"/>
<smd name="1" x="-0.85" y="0" dx="1.3" dy="1.5" layer="1"/>
<smd name="2" x="0.85" y="0" dx="1.3" dy="1.5" layer="1"/>
<text x="-0.762" y="1.016" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-2.286" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="0.4064" y1="-0.6985" x2="1.0564" y2="0.7015" layer="51"/>
<rectangle x1="-1.0668" y1="-0.6985" x2="-0.4168" y2="0.7015" layer="51"/>
<rectangle x1="-0.1999" y1="-0.5001" x2="0.1999" y2="0.5001" layer="35"/>
</package>
</packages>
<symbols>
<symbol name="MCP2551">
<wire x1="-20.32" y1="20.32" x2="7.62" y2="20.32" width="0.254" layer="97"/>
<wire x1="7.62" y1="20.32" x2="7.62" y2="-12.7" width="0.254" layer="97"/>
<wire x1="7.62" y1="-12.7" x2="-20.32" y2="-12.7" width="0.254" layer="97"/>
<wire x1="-20.32" y1="-12.7" x2="-20.32" y2="20.32" width="0.254" layer="97"/>
<pin name="TXD" x="-25.4" y="15.24" length="middle"/>
<pin name="VSS" x="-25.4" y="7.62" length="middle"/>
<pin name="VDD" x="-25.4" y="0" length="middle"/>
<pin name="RXD" x="-25.4" y="-7.62" length="middle"/>
<pin name="VREF" x="12.7" y="-7.62" length="middle" rot="R180"/>
<pin name="CANL" x="12.7" y="0" length="middle" rot="R180"/>
<pin name="CANH" x="12.7" y="7.62" length="middle" rot="R180"/>
<pin name="RS" x="12.7" y="15.24" length="middle" rot="R180"/>
</symbol>
<symbol name="R-US">
<wire x1="-2.54" y1="0" x2="-2.159" y2="1.016" width="0.2032" layer="94"/>
<wire x1="-2.159" y1="1.016" x2="-1.524" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="-1.524" y1="-1.016" x2="-0.889" y2="1.016" width="0.2032" layer="94"/>
<wire x1="-0.889" y1="1.016" x2="-0.254" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="-0.254" y1="-1.016" x2="0.381" y2="1.016" width="0.2032" layer="94"/>
<wire x1="0.381" y1="1.016" x2="1.016" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="1.016" y1="-1.016" x2="1.651" y2="1.016" width="0.2032" layer="94"/>
<wire x1="1.651" y1="1.016" x2="2.286" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="2.286" y1="-1.016" x2="2.54" y2="0" width="0.2032" layer="94"/>
<text x="-3.81" y="1.4986" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MCP2551">
<gates>
<gate name="G$1" symbol="MCP2551" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOIC8">
<connects>
<connect gate="G$1" pin="CANH" pad="7"/>
<connect gate="G$1" pin="CANL" pad="6"/>
<connect gate="G$1" pin="RS" pad="8"/>
<connect gate="G$1" pin="RXD" pad="4"/>
<connect gate="G$1" pin="TXD" pad="1"/>
<connect gate="G$1" pin="VDD" pad="3"/>
<connect gate="G$1" pin="VREF" pad="5"/>
<connect gate="G$1" pin="VSS" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RESISTOR" prefix="R" uservalue="yes">
<gates>
<gate name="G$1" symbol="R-US" x="0" y="0"/>
</gates>
<devices>
<device name="" package="R0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply2">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
Please keep in mind, that these devices are necessary for the
automatic wiring of the supply signals.&lt;p&gt;
The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.905" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="SUPPLY">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="GND" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Dash parts" deviceset="MCP2551" device=""/>
<part name="R4" library="Dash parts" deviceset="RESISTOR" device="" value="50"/>
<part name="R3" library="Dash parts" deviceset="RESISTOR" device="" value="50"/>
<part name="SUPPLY1" library="supply2" deviceset="GND" device=""/>
<part name="U$4" library="Dash parts" deviceset="MCP2551" device=""/>
<part name="SUPPLY2" library="supply2" deviceset="GND" device=""/>
<part name="R2" library="Dash parts" deviceset="RESISTOR" device="" value="120"/>
<part name="R1" library="Dash parts" deviceset="RESISTOR" device="" value="120"/>
<part name="R5" library="Dash parts" deviceset="RESISTOR" device="" value="50"/>
<part name="R6" library="Dash parts" deviceset="RESISTOR" device="" value="50"/>
<part name="SUPPLY3" library="supply2" deviceset="GND" device=""/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="P+2" library="supply1" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" deviceset="VCC" device=""/>
<part name="SUPPLY4" library="supply2" deviceset="GND" device=""/>
<part name="SUPPLY5" library="supply2" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="134.62" y1="81.28" x2="177.8" y2="81.28" width="0.1524" layer="97"/>
<wire x1="177.8" y1="81.28" x2="177.8" y2="10.16" width="0.1524" layer="97"/>
<wire x1="177.8" y1="10.16" x2="134.62" y2="10.16" width="0.1524" layer="97"/>
<wire x1="134.62" y1="10.16" x2="134.62" y2="12.7" width="0.1524" layer="97"/>
<text x="134.62" y="71.12" size="1.778" layer="97">Tx</text>
<text x="134.62" y="60.96" size="1.778" layer="97">Rx</text>
<text x="134.62" y="48.26" size="1.778" layer="97">Dac0</text>
<text x="134.62" y="35.56" size="1.778" layer="97">53</text>
<text x="134.62" y="22.86" size="1.778" layer="97">Vdd</text>
<text x="134.62" y="12.7" size="1.778" layer="97">GRD</text>
<wire x1="134.62" y1="12.7" x2="134.62" y2="35.56" width="0.1524" layer="97"/>
<wire x1="134.62" y1="35.56" x2="134.62" y2="48.26" width="0.1524" layer="97"/>
<wire x1="134.62" y1="48.26" x2="134.62" y2="60.96" width="0.1524" layer="97"/>
<wire x1="134.62" y1="60.96" x2="134.62" y2="71.12" width="0.1524" layer="97"/>
<wire x1="134.62" y1="71.12" x2="134.62" y2="81.28" width="0.1524" layer="97"/>
<wire x1="27.94" y1="63.5" x2="27.94" y2="53.34" width="0.1524" layer="97"/>
<wire x1="27.94" y1="53.34" x2="104.14" y2="53.34" width="0.1524" layer="97"/>
<wire x1="134.62" y1="60.96" x2="104.14" y2="60.96" width="0.1524" layer="97"/>
<wire x1="104.14" y1="60.96" x2="104.14" y2="53.34" width="0.1524" layer="97"/>
<wire x1="27.94" y1="86.36" x2="27.94" y2="96.52" width="0.1524" layer="97"/>
<wire x1="27.94" y1="96.52" x2="121.92" y2="96.52" width="0.1524" layer="97"/>
<wire x1="121.92" y1="96.52" x2="121.92" y2="71.12" width="0.1524" layer="97"/>
<wire x1="121.92" y1="71.12" x2="134.62" y2="71.12" width="0.1524" layer="97"/>
<wire x1="27.94" y1="10.16" x2="27.94" y2="35.56" width="0.1524" layer="97"/>
<wire x1="27.94" y1="35.56" x2="134.62" y2="35.56" width="0.1524" layer="97"/>
<wire x1="27.94" y1="-12.7" x2="27.94" y2="-20.32" width="0.1524" layer="97"/>
<wire x1="27.94" y1="-20.32" x2="114.3" y2="-20.32" width="0.1524" layer="97"/>
<wire x1="134.62" y1="48.26" x2="114.3" y2="48.26" width="0.1524" layer="97"/>
<wire x1="114.3" y1="48.26" x2="114.3" y2="-20.32" width="0.1524" layer="97"/>
<wire x1="129.54" y1="5.08" x2="129.54" y2="12.7" width="0.1524" layer="97"/>
<wire x1="129.54" y1="12.7" x2="134.62" y2="12.7" width="0.1524" layer="97"/>
<wire x1="134.62" y1="78.74" x2="167.64" y2="78.74" width="0.1524" layer="96" style="shortdash"/>
<wire x1="167.64" y1="78.74" x2="167.64" y2="58.42" width="0.1524" layer="96" style="shortdash"/>
<wire x1="167.64" y1="58.42" x2="134.62" y2="58.42" width="0.1524" layer="96" style="shortdash"/>
<wire x1="134.62" y1="53.34" x2="167.64" y2="53.34" width="0.1524" layer="96" style="shortdash"/>
<wire x1="167.64" y1="53.34" x2="167.64" y2="33.02" width="0.1524" layer="96" style="shortdash"/>
<wire x1="167.64" y1="33.02" x2="134.62" y2="33.02" width="0.1524" layer="96" style="shortdash"/>
<wire x1="134.62" y1="33.02" x2="134.62" y2="35.56" width="0.1524" layer="96" style="shortdash"/>
<text x="147.32" y="68.58" size="1.778" layer="96">CAN0</text>
<text x="149.86" y="43.18" size="1.778" layer="96">CAN1</text>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="53.34" y="71.12"/>
<instance part="R4" gate="G$1" x="40.64" y="48.26"/>
<instance part="R3" gate="G$1" x="68.58" y="43.18" rot="R90"/>
<instance part="SUPPLY1" gate="GND" x="68.58" y="30.48"/>
<instance part="U$4" gate="G$1" x="53.34" y="-5.08"/>
<instance part="SUPPLY2" gate="GND" x="68.58" y="-45.72"/>
<instance part="R2" gate="G$1" x="83.82" y="12.7"/>
<instance part="R1" gate="G$1" x="83.82" y="60.96"/>
<instance part="R5" gate="G$1" x="40.64" y="-27.94"/>
<instance part="R6" gate="G$1" x="68.58" y="-33.02" rot="R90"/>
<instance part="SUPPLY3" gate="GND" x="129.54" y="2.54"/>
<instance part="P+1" gate="VCC" x="124.46" y="27.94"/>
<instance part="P+2" gate="VCC" x="2.54" y="81.28"/>
<instance part="P+3" gate="VCC" x="2.54" y="5.08"/>
<instance part="SUPPLY4" gate="GND" x="17.78" y="0"/>
<instance part="SUPPLY5" gate="GND" x="17.78" y="76.2"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$3" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="2"/>
<wire x1="45.72" y1="48.26" x2="68.58" y2="48.26" width="0.1524" layer="91"/>
<wire x1="68.58" y1="48.26" x2="68.58" y2="63.5" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="VREF"/>
<wire x1="68.58" y1="63.5" x2="66.04" y2="63.5" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="2"/>
<junction x="68.58" y="48.26"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="R3" gate="G$1" pin="1"/>
<wire x1="68.58" y1="38.1" x2="68.58" y2="33.02" width="0.1524" layer="91"/>
<pinref part="SUPPLY1" gate="GND" pin="GND"/>
</segment>
<segment>
<wire x1="68.58" y1="-38.1" x2="68.58" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="SUPPLY2" gate="GND" pin="GND"/>
<pinref part="R6" gate="G$1" pin="1"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="VSS"/>
<wire x1="27.94" y1="2.54" x2="17.78" y2="2.54" width="0.1524" layer="91"/>
<wire x1="17.78" y1="2.54" x2="12.7" y2="2.54" width="0.1524" layer="91"/>
<wire x1="12.7" y1="2.54" x2="12.7" y2="22.86" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="RS"/>
<wire x1="12.7" y1="22.86" x2="66.04" y2="22.86" width="0.1524" layer="91"/>
<wire x1="66.04" y1="22.86" x2="66.04" y2="10.16" width="0.1524" layer="91"/>
<pinref part="SUPPLY4" gate="GND" pin="GND"/>
<junction x="17.78" y="2.54"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="VSS"/>
<wire x1="27.94" y1="78.74" x2="17.78" y2="78.74" width="0.1524" layer="91"/>
<wire x1="17.78" y1="78.74" x2="12.7" y2="78.74" width="0.1524" layer="91"/>
<wire x1="12.7" y1="78.74" x2="12.7" y2="99.06" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="RS"/>
<wire x1="12.7" y1="99.06" x2="66.04" y2="99.06" width="0.1524" layer="91"/>
<wire x1="66.04" y1="99.06" x2="66.04" y2="86.36" width="0.1524" layer="91"/>
<pinref part="SUPPLY5" gate="GND" pin="GND"/>
<junction x="17.78" y="78.74"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<wire x1="45.72" y1="-27.94" x2="68.58" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="68.58" y1="-27.94" x2="68.58" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="VREF"/>
<wire x1="68.58" y1="-12.7" x2="66.04" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="R5" gate="G$1" pin="2"/>
<pinref part="R6" gate="G$1" pin="2"/>
<junction x="68.58" y="-27.94"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="CANL"/>
<wire x1="66.04" y1="71.12" x2="78.74" y2="71.12" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="CANL"/>
<wire x1="78.74" y1="71.12" x2="78.74" y2="60.96" width="0.1524" layer="91"/>
<wire x1="78.74" y1="60.96" x2="78.74" y2="12.7" width="0.1524" layer="91"/>
<wire x1="78.74" y1="12.7" x2="78.74" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="78.74" y1="-5.08" x2="66.04" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="R2" gate="G$1" pin="1"/>
<junction x="78.74" y="12.7"/>
<pinref part="R1" gate="G$1" pin="1"/>
<junction x="78.74" y="60.96"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="CANH"/>
<wire x1="66.04" y1="78.74" x2="88.9" y2="78.74" width="0.1524" layer="91"/>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="88.9" y1="78.74" x2="88.9" y2="60.96" width="0.1524" layer="91"/>
<wire x1="88.9" y1="60.96" x2="88.9" y2="12.7" width="0.1524" layer="91"/>
<wire x1="88.9" y1="12.7" x2="88.9" y2="2.54" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="CANH"/>
<wire x1="88.9" y1="2.54" x2="66.04" y2="2.54" width="0.1524" layer="91"/>
<junction x="88.9" y="12.7"/>
<pinref part="R1" gate="G$1" pin="2"/>
<junction x="88.9" y="60.96"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VDD"/>
<wire x1="27.94" y1="71.12" x2="12.7" y2="71.12" width="0.1524" layer="91"/>
<wire x1="12.7" y1="71.12" x2="12.7" y2="48.26" width="0.1524" layer="91"/>
<pinref part="R4" gate="G$1" pin="1"/>
<wire x1="12.7" y1="48.26" x2="35.56" y2="48.26" width="0.1524" layer="91"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
<wire x1="12.7" y1="71.12" x2="2.54" y2="71.12" width="0.1524" layer="91"/>
<wire x1="2.54" y1="71.12" x2="2.54" y2="78.74" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="VDD"/>
<wire x1="27.94" y1="-5.08" x2="12.7" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-5.08" x2="12.7" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-27.94" x2="35.56" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="R5" gate="G$1" pin="1"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
<wire x1="12.7" y1="-5.08" x2="2.54" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="2.54" y1="-5.08" x2="2.54" y2="2.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="124.46" y1="25.4" x2="124.46" y2="22.86" width="0.1524" layer="91"/>
<wire x1="124.46" y1="22.86" x2="134.62" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
