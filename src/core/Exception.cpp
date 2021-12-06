//
// Created by NaturalVStudio on 2021/12/2.
//

#include "Exception.h"
#include <iostream>

/**
 * �����쳣���쳣�����ʽ��
 * ʹ��int32������Ϊ�쳣��ţ���ǰ��λ�����쳣���ͺţ�����λΪ�쳣���
 * * * * * * *  *  *  *  * * * * * *
 * ����0000�������ֶΣ�ϵͳ�����쳣
 * ����0001�������﷨�������
 * ����0002��tableԼ�����
 * ����0003�������ֵ��쳣
 *
 * ����1111�����쳣����
 *
 * @return ExcpList
 */
std::unordered_map<int32_t, std::string> Exception::CreateExcpList() {
    std::unordered_map<int32_t , std::string> temp;

    temp[0x00010001] = "zDB�쳣[0x00010001]: ���ÿհ��ַ��ָ�SQL���";
    temp[0x00010002] = "zDB�쳣[0x00010002]: �Ƿ�SQL��䣬����";
    temp[0x00010003] = "zDB�쳣[0x00010003]: ������create��������ѡ�table, index, view";
    temp[0x00010004] = "zDB�쳣[0x00010004]: insert�����������";

    temp[0x00020001] = "zDB�쳣[0x00020001]: �Ѵ��ڸñ�";
    temp[0x00020002] = "zDB�쳣[0x00020002]: ��������ȱʧ���У�����";

    temp[0x00030001] = "zDB�쳣[0x00030001]: ���ݿ����޴˱�";

    temp[0x11110001] = "zDB����[0x11110001]: ��miss���ڴ���ȱʧ�˱����ڶ�ȡ����ļ�";
    return temp;
}

void Exception::RaiseException(int32_t ExcpCode) {
    std::cout << exceptionList[ExcpCode] << std::endl;
}
std::unordered_map<int32_t , std::string> Exception::exceptionList = Exception::CreateExcpList();
