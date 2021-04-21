<?xml version="1.0"?>
<!--
    Document   : TECOMP.xsl
    Created on : September 25, 2019, 3:18 PM
    Author     : universe
    Description:
        Purpose of transformation follows.
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>

    <!-- TODO customize transformation rules 
         syntax recommendation http://www.w3.org/TR/xslt 
    -->
    <xsl:template match="/">
        <html>
            <head>
                <title>TECOMP.xsl</title>
            </head>
            <body>
                 <table border="1">
                    <tr>
                        <th>Name</th>
                        <th>Roll no.</th>
                    </tr>
                    <xsl:for-each select="root/college/class">
                        <tr>
                            <td> 
                                <xsl:value-of select="name"></xsl:value-of>                        
                            </td>
                            <td>
                                <xsl:value-of select="department"></xsl:value-of>

                            </td>
                            <td>
                                <xsl:value-of select="rollno"></xsl:value-of>
                            </td>
                        </tr>
                     </xsl:for-each>     
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
