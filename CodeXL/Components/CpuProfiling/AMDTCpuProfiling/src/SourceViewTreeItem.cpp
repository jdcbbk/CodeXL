//==================================================================================
// Copyright (c) 2012-2016 , Advanced Micro Devices, Inc.  All rights reserved.
//
/// \author AMD Developer Tools Team
/// \file SourceViewTreeItem.cpp
///
//==================================================================================
// $Id: //devtools/main/CodeXL/Components/CpuProfiling/AMDTCpuProfiling/src/SourceViewTreeItem.cpp#8 $
// Last checkin:   $DateTime: 2012/07/06 14:25:46 $
// Last edited by: $Author:  AMD Developer Tools Team
// Change list:    $Change: 446204 $
//=============================================================

// Qt:
#include <qtIgnoreCompilerWarnings.h>
#include <QtWidgets>

// Infra:
#include <AMDTBaseTools/Include/gtAssert.h>

// Local:
#include <inc/SourceViewTreeItem.h>

SourceViewTreeItem::SourceViewTreeItem(SOURCE_TREE_ITEM_DEPTH dep, SourceViewTreeItem* pParentItem) :
    m_pParentItem(pParentItem)
{
    (void)dep; //unused

    if (pParentItem != nullptr)
    {
        pParentItem->appendChild(this);
    }
}

SourceViewTreeItem::SourceViewTreeItem(const QVector<QVariant>& data, SourceViewTreeItem* pParentItem) :
    m_itemData(data),
    m_pParentItem(pParentItem)
{
    if (pParentItem != nullptr)
    {
        pParentItem->appendChild(this);
    }
}

SourceViewTreeItem::~SourceViewTreeItem()
{
    qDeleteAll(m_childItems);
    m_childItems.clear();

    m_itemData.clear();
    m_itemTooltip.clear();
    m_itemForegrounds.clear();
    m_pParentItem = nullptr;

#ifdef CLU_TAB
    delete m_pCLUData;
    m_pCLUData = nullptr;
#endif
}

SourceViewTreeItem* SourceViewTreeItem::child(int index) const
{
    SourceViewTreeItem* pChild = nullptr;

    if ((index >= 0) && (index < m_childItems.size()))
    {
        pChild = m_childItems[index];
    }

    return pChild;
}

int SourceViewTreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant SourceViewTreeItem::data(int column) const
{
    return m_itemData.value(column);
}

QVariant SourceViewTreeItem::tooltip(int column) const
{
    return m_itemTooltip.value(column);
}

bool SourceViewTreeItem::appendChild(SourceViewTreeItem* pChild)
{
    bool retVal = false;

    if (pChild != nullptr)
    {
        m_childItems.append(pChild);
        retVal = true;
    }

    return retVal;
}

bool SourceViewTreeItem::insertChild(int position, SourceViewTreeItem* pChild)
{
    bool retVal = false;

    GT_IF_WITH_ASSERT((position >= 0) && (position < m_childItems.size()) && pChild != nullptr)
    {
        m_childItems.insert(position, pChild);
        retVal = true;
    }

    return retVal;
}

bool SourceViewTreeItem::insertChildren(int position, int count, int columns)
{
    // Insert given number of children with given number of columns at the given position.
    bool retVal = false;

    GT_IF_WITH_ASSERT((position >= 0) && (position < m_childItems.size()))
    {
        for (int row = 0; row < count; ++row)
        {
            QVector<QVariant> data(columns);
            SourceViewTreeItem* pItem = new SourceViewTreeItem(data, this);

            // Insert the new child:
            m_childItems.insert(position, pItem);
        }

        retVal = true;
    }

    return retVal;
}

bool SourceViewTreeItem::insertColumns(int position, int columns)
{
    // Insert given number of columns to the parent and all the children recursively.
    bool retVal = false;

    if (position >= 0 && position < m_itemData.size())
    {
        for (int column = 0; column < columns; ++column)
        {
            m_itemData.insert(position, QVariant());
        }

        for (auto pChild : m_childItems)
        {
            GT_IF_WITH_ASSERT(pChild != nullptr)
            {
                pChild->insertColumns(position, columns);
            }
        }

        retVal = true;
    }

    return retVal;
}

SourceViewTreeItem* SourceViewTreeItem::parent() const
{
    return m_pParentItem;
}

int SourceViewTreeItem::row() const
{
    if (m_pParentItem != nullptr)
    {
        return m_pParentItem->m_childItems.indexOf(const_cast<SourceViewTreeItem*>(this));
    }

    return 0;
}

bool SourceViewTreeItem::removeChildren(int position, int count)
{
    bool retVal = false;
    int endPosition = position + count - 1;

    GT_IF_WITH_ASSERT((position >= 0) && (endPosition < m_childItems.size()))
    {
        for (int row = endPosition; row >= position; row--)
        {
            // Remove the item from the list, and delete it:
            delete m_childItems.takeAt(row);
        }

        retVal = true;
    }

    return retVal;
}

bool SourceViewTreeItem::removeColumns(int position, int columns)
{
    bool retVal = false;
    int endPosition = position + columns - 1;

    if (position >= 0 && endPosition < m_itemData.size())
    {
        for (int column = 0; column < columns; ++column)
        {
            m_itemData.remove(position);
        }

        for (auto pChild : m_childItems)
        {
            pChild->removeColumns(position, columns);
        }
    }

    return retVal;
}

bool SourceViewTreeItem::setData(int column, const QVariant& value)
{
    bool retVal = false;

    if (column >= m_itemData.size())
    {
        m_itemData.resize(column + 1);
    }

    GT_IF_WITH_ASSERT((column >= 0) && (column < m_itemData.size()))
    {
        m_itemData[column] = value;
        retVal = true;
    }

    return retVal;
}

bool SourceViewTreeItem::setTooltip(int column, const QVariant& value)
{
    bool retVal = false;

    if (column >= m_itemTooltip.size())
    {
        m_itemTooltip.resize(column + 1);
    }

    GT_IF_WITH_ASSERT((column >= 0) && (column < m_itemTooltip.size()))
    {
        m_itemTooltip[column] = value;
        retVal = true;
    }

    return retVal;
}

bool SourceViewTreeItem::setForeground(int column, const QColor& color)
{
    bool retVal = false;

    if (column >= m_itemForegrounds.size())
    {
        for (int i = m_itemForegrounds.size(); i <= column; i++)
        {
            m_itemForegrounds << Qt::black;
        }
    }

    GT_IF_WITH_ASSERT((column >= 0) && (column < m_itemForegrounds.size()))
    {
        m_itemForegrounds[column] = color;
        retVal = true;
    }

    return retVal;
}

int SourceViewTreeItem::indexOfChild(SourceViewTreeItem* pItem) const
{
    return m_childItems.indexOf(pItem);
}

QColor SourceViewTreeItem::forground(int column) const
{
    QColor color = Qt::black;

    if ((column >= 0) && (column < m_itemForegrounds.size()))
    {
        color = m_itemForegrounds[column];
    }

    return color;
}

#if AMDT_BUILD_CONFIGURATION == AMDT_DEBUG_BUILD
#include <AMDTOSWrappers/Include/osDebuggingFunctions.h>

void SourceViewTreeItem::DebugPrintChildrenList()
{
    gtString outputStr;

    if (m_pParentItem != nullptr)
    {
        outputStr.append(L"Parent data: ");
        outputStr.append(m_pParentItem->data(SOURCE_VIEW_LINE_COLUMN).toString().toStdWString().c_str());
        outputStr.append(L"\nParent children: \n");

        // Print all the children of the item's parent:
        for (int i = 0 ; i < m_pParentItem->m_childItems.size(); i++)
        {
            SourceViewTreeItem* pChild = m_pParentItem->m_childItems[i];

            if (pChild != nullptr)
            {
                outputStr.appendFormattedString(L"Child %d: %ls\n", i, pChild->data(SOURCE_VIEW_ADDRESS_COLUMN).toString().toStdWString().c_str());
            }
        }
    }

    outputStr.append(L"Children:\n");

    for (int i = 0 ; i < m_childItems.size(); i++)
    {
        SourceViewTreeItem* pChild = m_childItems[i];

        if (pChild != nullptr)
        {
            QString dataStr = pChild->data(SOURCE_VIEW_ADDRESS_COLUMN).toString();

            if (dataStr.isEmpty())
            {
                dataStr = pChild->data(SOURCE_VIEW_SOURCE_COLUMN).toString();
            }

            outputStr.appendFormattedString(L"Child %d: %ls\n", i, dataStr.toStdWString().c_str());
        }
    }

    osOutputDebugString(outputStr);
}

#endif
