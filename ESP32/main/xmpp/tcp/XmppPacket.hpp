#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <smooth/core/network/IPacketDisassembly.h>

//---------------------------------------------------------------------------
namespace espiot::xmpp::tcp {
//---------------------------------------------------------------------------
class XmppPacket : public smooth::core::network::IPacketDisassembly {
    public:
    static const size_t PACKET_SIZE = 1024;

    private:
    std::vector<uint8_t> data{};

    public:
    XmppPacket() = default;
    XmppPacket(const XmppPacket&) = default;
    XmppPacket(XmppPacket&&) = default;

    explicit XmppPacket(std::vector<uint8_t>& data);
    explicit XmppPacket(std::wstring& data);
    explicit XmppPacket(std::string& data);

    XmppPacket& operator=(const XmppPacket&) = default;

    /**
     * Must return the total amount of bytes to send.
     **/
    int get_send_length() override;
    /**
     * Must return a pointer to the data to be sent.
     **/
    const uint8_t* get_data() override;
    std::vector<uint8_t>& get_data_vec();
    [[nodiscard]] const std::vector<uint8_t>& get_data_vec() const;
    [[nodiscard]] std::wstring to_wstring() const;
    [[nodiscard]] std::string to_string() const;
    [[nodiscard]] std::size_t size() const;
    void resize(std::size_t newSize);
};
//---------------------------------------------------------------------------
} // namespace espiot::xmpp::tcp
//---------------------------------------------------------------------------
