<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body>
                <h2>My CD Collection</h2>
                <table border="1">
                    <tr bgcolor="#9acd32">
                        <th>Title</th>
                        <th>Artist</th>
                        <th>Country</th>
                        <th>Company</th>
                        <th>Price</th>
                        <th>Year</th>
                    </tr>
                    <xsl:for-each select="CATALOG/CD">
                        <tr>
                            <td>
                                <xsl:value-of select="TITLE" />
                            </td>
                            <xsl:choose>

                                <xsl:when test="PRICE &gt; 10">
                                    <td bgcolor="Green">
                                        <xsl:value-of select="ARTIST" />
                                    </td>
                                </xsl:when>
                                <xsl:otherwise>
                                    <td bgcolor="red">
                                        <xsl:value-of select="ARTIST" />
                                    </td>
                                </xsl:otherwise>
                            </xsl:choose>
                            <xsl:choose>

                                <xsl:when test="PRICE &gt; 10">
                                    <td bgcolor="Green">
                                        <xsl:value-of select="COUNTRY" />
                                    </td>
                                </xsl:when>
                                <xsl:otherwise>
                                    <td bgcolor="red">
                                        <xsl:value-of select="COUNTRY" />
                                    </td>
                                </xsl:otherwise>
                            </xsl:choose>
                            <xsl:choose>

                                <xsl:when test="PRICE &gt; 10">
                                    <td bgcolor="Green">
                                        <xsl:value-of select="COMPANY" />
                                    </td>
                                </xsl:when>
                                <xsl:otherwise>
                                    <td bgcolor="red">
                                        <xsl:value-of select="COMPANY" />
                                    </td>
                                </xsl:otherwise>
                            </xsl:choose>
                            <xsl:choose>

                                <xsl:when test="PRICE &gt; 10">
                                    <td bgcolor="Green">
                                        <xsl:value-of select="PRICE" />
                                    </td>
                                </xsl:when>
                                <xsl:otherwise>
                                    <td bgcolor="red">
                                        <xsl:value-of select="PRICE" />
                                    </td>
                                </xsl:otherwise>
                            </xsl:choose>
                            <xsl:choose>

                                <xsl:when test="PRICE &gt; 10">
                                    <td bgcolor="Green">
                                        <xsl:value-of select="YEAR" />
                                    </td>
                                </xsl:when>
                                <xsl:otherwise>
                                    <td bgcolor="red">
                                        <xsl:value-of select="YEAR" />
                                    </td>
                                </xsl:otherwise>
                            </xsl:choose>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>