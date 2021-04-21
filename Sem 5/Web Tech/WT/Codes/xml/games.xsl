<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body>
                <h2>My Game Collection</h2>
                <table border="1">
                    <tr bgcolor="lightblue">
                        <th>Name</th>
                        <th>Developer</th>
                        <th>Year Released</th>
                        <th>Price</th>
                    </tr>
                    <xsl:for-each select="games/game">
                        <tr style="text-align: center;">
                            <td><xsl:value-of select="title"/></td>
                            <td><xsl:value-of select="developer"/></td>
                            <td><xsl:value-of select="year"/></td>
                            <td><xsl:value-of select="price"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>