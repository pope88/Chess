HANDLER_CLASS(PlayerOperate, 0x14)
{
	UInt32 chips = 0;
	if (pkt.HasChips())
	{
		chips = pkt.Chips();
	}
    user->getThePlayer()->onOperateAck(pkt.Opcode(), chips);
}
HANDLER_END(PlayerOperate)
